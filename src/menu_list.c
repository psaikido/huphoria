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
	// char choice;

	printf("=^ huphoria::[m]enu ^=\n");

	FILE *f = getFile();

	int i = 1;
	char line[255];
	// char *lines;

    while (fgets(line, sizeof(line), f)) {
		printf("[%d]: %s", i++, line);
    }

	fclose(f);
	fire();
}

void fire() {
	int choice;
	choice = getchar();
	printf("%d\n", choice);
}

void huf_save() {
	printf("the save\n");
}

void huf_copy() {
	printf("the copy\n");
}

void huf_categories() {
	printf("the categories\n");
}

void huf_edit() {
	printf("the edit\n");
}

void huf_quit() {
	exit(0);
}

