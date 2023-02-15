#include <stdio.h>
#include "../include/huf_menu_funcs.h" 

int main() {
	int choice;

	printf("1 list\n");
	printf("2 save\n");
	printf("3 copy\n");
	printf("4 categories\n");
	printf("5 edit\n");
	printf("6 quit\n");

	scanf("%d", &choice);

	switch (choice) {
		case 1:
			huf_list();
		break;

		case 2:
			printf("save\n");
		break;

		case 3:
			printf("copy\n");
		break;

		case 4:
			printf("categories\n");
		break;

		case 5:
			printf("edit\n");
		break;

		case 6:
			printf("quit\n");
		break;
	}

	return 0;
}
