#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "../include/huf_menu_funcs.h" 

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

void huf_menu(WINDOW * menuwin) {
	int i = 0;
	mvwprintw(menuwin, 1 + i++, 1, "%s\n", "[l]ist");
	mvwprintw(menuwin, 1 + i++, 1, "%s\n", "[s]ave\n");
	mvwprintw(menuwin, 1 + i++, 1, "%s\n", "[c]opy\n");
	mvwprintw(menuwin, 1 + i++, 1, "%s\n", "c[a]tegories\n");
	mvwprintw(menuwin, 1 + i++, 1, "%s\n", "[e]dit\n");
	mvwprintw(menuwin, 1 + i++, 1, "%s\n", "c[o]nfigure\n");
	mvwprintw(menuwin, 1 + i++, 1, "%s\n", "[q]uit\n");
	wrefresh(menuwin);
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

