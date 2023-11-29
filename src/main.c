#include <curses.h>
#include <ncurses.h>
#include <menu.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../include/huf_menu_funcs.h" 

WINDOW* mainwin;
WINDOW* menuwin;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define ENTER '\n'


int main() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED,     COLOR_BLACK);
        init_pair(2, COLOR_GREEN,   COLOR_BLACK);
        init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
        init_pair(4, COLOR_BLUE,    COLOR_BLACK);
        init_pair(5, COLOR_CYAN,    COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE,   COLOR_BLACK);
    }

	int x, y;
	getmaxyx(stdscr, y, x);

	menuwin = newwin(y, 20, 0, 0);
	keypad(menuwin, TRUE);
	box(menuwin, 0, 0);

	mainwin = newwin(y, x - 18, 1, 21);
	keypad(mainwin, TRUE);

	huf_menu();

	endwin();

	return 0;
}


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


void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color) {
	int length, x, y;
	float temp;

	if(win == NULL) {
		win = stdscr;
	}

	getyx(win, y, x);

	if(startx != 0) {
		x = startx;
	}

	if(starty != 0) {
		y = starty;
	}

	if(width == 0) {
		width = 80;
	}

	length = strlen(string);
	temp = (width - length) / 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}


void huf_menu() {
	ITEM **the_items;
	MENU *the_menu;
	int n_choices;
	int c;

	char *choices[] = {
		"list",
		"save",
		"copy",
		"categories",
		"edit",
		"configure",
		"quit"
	};

	n_choices = ARRAY_SIZE(choices);
	the_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	wattron(mainwin, COLOR_PAIR(3));
	for(int i = 0; i < n_choices; ++i) {
		the_items[i] = new_item(choices[i], "");
	}
	wattroff(mainwin, COLOR_PAIR(3));

	the_items[n_choices] = (ITEM *)NULL;
	the_menu = new_menu((ITEM **)the_items);
	set_menu_sub(the_menu, derwin(menuwin, 8, 18, 3, 1));
	set_menu_win(the_menu, menuwin);
	set_menu_mark(the_menu, " *");
	set_menu_back(the_menu, COLOR_PAIR(4));

	print_in_middle(menuwin, 1, 0, 20, " == huphoria == ", COLOR_PAIR(3));

	post_menu(the_menu);
	wrefresh(menuwin);

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
				process_menu_choice(item_index(cur));
			}
			break;
		}

		wrefresh(menuwin);
	}
}


void process_menu_choice(int x) {
	wclear(mainwin);
	wattron(mainwin, COLOR_PAIR(3));

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

	wattroff(mainwin, COLOR_PAIR(3));
	wrefresh(mainwin);
}


void huf_list() {
	FILE *f = getFile();

	int i = 1;
	char line[255];

    while (fgets(line, sizeof(line), f)) {
		wprintw(mainwin, "[%d]: %s", i++, line);
    }

	fclose(f);
}


void huf_edit() {
	wprintw(mainwin, "the edit");
}


void huf_save() {
	wprintw(mainwin, "the save");
}


void huf_copy() {
	wprintw(mainwin, "the copy");
}


void huf_categories() {
	wprintw(mainwin, "the categories");
}


void huf_configure() {
	wprintw(mainwin, "the configure");
}


void huf_quit() {
	exit(0);
}

