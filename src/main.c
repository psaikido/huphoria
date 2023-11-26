#include <ncurses.h>
#include <stdio.h>
#include "../include/huf_menu_funcs.h" 
#include "../include/huf_configure.h" 

int main() {
	char choice = 'l';
	huf_list();

	while (1 == 1) {
		choice = getchar();

		switch (choice) {
			case 'l':
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
				printf("[l]ist\n");
				printf("[s]ave\n");
				printf("[c]opy\n");
				printf("c[a]tegories\n");
				printf("[e]dit\n");
				printf("c[o]nfigure\n");
				printf("[q]uit\n");
				break;

			default:
				printf("Choose one of the bracketed letters\n");
		}
	}

	return 0;
}
