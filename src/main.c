#include <stdio.h>
#include "../include/huf_menu_funcs.h" 
#include "../include/huf_configure.h" 

int main() {
	char choice;

	printf("[l]ist\n");
	printf("[s]ave\n");
	printf("[c]opy\n");
	printf("c[a]tegories\n");
	printf("[e]dit\n");
	printf("c[o]figure\n");
	printf("[q]uit\n");

	choice = getchar();

	switch (choice) {
		case 'l':
			huf_list();
		break;

		case 's':
			printf("save\n");
		break;

		case 'c':
			printf("copy\n");
		break;

		case 'a':
			printf("categories\n");
		break;

		case 'e':
			printf("edit\n");
		break;

		case 'o':
			huf_configure();
		break;

		case 'q':
			printf("quit\n");
		break;

		default:
			printf("Choose one of the bracketed letters\n");
		break;
	}

	return 0;
}
