#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/huf_menu_funcs.h" 
#include "../include/huf_configure.h" 

int main() {
	initscr();
	cbreak();
	noecho();

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

	attrset(COLOR_PAIR(3));
	addstr("");
	addstr("=== huphoria [m]enu ===\n");
	huf_list();
	refresh();

    for (;;) {

		char choice = getch();

		switch (choice) {
			case 'l':
				clear();
				huf_list();
				break;

			case 's':
				huf_save();
				break;

			case 'c':
				huf_copy();
				break;

			case 'a':
				huf_categories();
				break;

			case 'e':
				huf_edit();
				break;

			case 'o':
				huf_configure();
				break;

			case 'q':
				huf_quit();
				break;

			case 'm':
				clear();
				printw("[l]ist\n");
				printw("[s]ave\n");
				printw("[c]opy\n");
				printw("c[a]tegories\n");
				printw("[e]dit\n");
				printw("c[o]nfigure\n");
				printw("[q]uit\n");
				break;

			default:
				printf("Choose one of the bracketed letters\n");
		}

		refresh();
    }

	endwin();

	// char choice = 'l';
	// huf_list();
	//
	// while (1 == 1) {
	// 	choice = getchar();
	//
	// }

	return 0;
}
