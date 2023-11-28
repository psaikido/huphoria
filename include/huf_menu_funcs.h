#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void huf_list();
void huf_menu();
void huf_save();
void huf_copy();
void huf_categories();
void huf_configure();
void huf_edit();
void huf_quit();
void print_in_middle(WINDOW *win, int starty, int startx, int width,
                     char *string, chtype color);
void process_menu_choice(int x);
