#include <curses.h>
#include <ncurses.h>
#include <menu.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/huf_menu_funcs.h" 
#include "../include/huf_configure.h" 

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define ENTER '\n'

FILE* getFile() {
	char filename[100];
	strcpy (filename, getenv("HOME"));
	strcat (filename, "/code/huphoria/data/data.txt");

	FILE *f = NULL;
	
	errno = 0;
	f = fopen(filename, "r");

	if (f == NULL) {
		fprintf(stderr, "Error opening %s for reading, errno: %d\n", filename, errno);
		exit(1);
	} else {
		return f;
	}
}

void huf_list() {
	FILE *f = getFile();

	int i = 1;
	char line[255];

    while (fgets(line, sizeof(line), f)) {
		printw("[%d]: %s", i++, line);
    }

	fclose(f);
	// fire();
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

void huf_menu() {
	WINDOW *menuwin;
	ITEM **the_items;
	MENU *the_menu;
	int n_choices;

	char *choices[] = {
		"[l] list",
		"[s] save",
		"[c] copy",
		"[a] categories",
		"[e] edit",
		"[o] configure",
		"[q] quit"
	};

	n_choices = ARRAY_SIZE(choices);
	the_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(int i = 0; i < n_choices; ++i) {
		the_items[i] = new_item(choices[i], "");
	}

	the_items[n_choices] = (ITEM *)NULL;
	the_menu = new_menu((ITEM **)the_items);

	menuwin = newwin(11, 40, 1, 4);
	keypad(menuwin, TRUE);
     
	/* Set main window and sub window */
	set_menu_win(the_menu, menuwin);
	set_menu_sub(the_menu, derwin(menuwin, 8, 38, 3, 1));

	/* Set menu mark to the string " * " */
	set_menu_mark(the_menu, " * ");

	/* Print a border around the main window and print a title */
	box(menuwin, 0, 0);
	print_in_middle(menuwin, 1, 0, 40, "=== huphoria [m]enu ===", COLOR_PAIR(3));
	mvwaddch(menuwin, 2, 0, ACS_LTEE);
	mvwhline(menuwin, 2, 1, ACS_HLINE, 38);
	mvwaddch(menuwin, 2, 39, ACS_RTEE);

	post_menu(the_menu);
	wrefresh(menuwin);

	int c;

	while((c = wgetch(menuwin)) != 'q') {
		switch(c) {	
			case KEY_DOWN:
			case 'j':
				menu_driver(the_menu, REQ_DOWN_ITEM);
			break;

			case KEY_UP:
			case 'k':
				menu_driver(the_menu, REQ_UP_ITEM);
			break;

			case ENTER: {	
				ITEM *cur = current_item(the_menu);
				process_menu_choice(menuwin, item_index(cur));
			}
			break;
		}

		wrefresh(menuwin);
	}
}

void process_menu_choice(WINDOW* menu, int x) {
	// wprintw(menu, "%d", x);
	clear();

	switch (x) {
		case 0:
			huf_list();
		break;
		case 1:
			huf_save();
		break;
		case 2:
			huf_copy();
		break;
		case 3:
			huf_categories();
		break;
		case 4:
			huf_edit();
		break;
		case 5:
			huf_configure();
		break;
		case 6:
			huf_quit();
		break;
	}

	refresh();
}

void fire() {
	int choice;
	choice = getchar();
	printw("%d\n", choice);
}

void huf_save() {
	printw("the save\n");
}

void huf_copy() {
	printw("the copy\n");
}

void huf_categories() {
	printw("the categories\n");
}

void huf_edit() {
	printw("the edit\n");
}

void huf_quit() {
	exit(0);
}

