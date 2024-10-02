#ifndef MENU_H
#define MENU_H

#include <ncurses.h>

WINDOW* createWindow(int, int);
int setTitle(WINDOW*, const char*);
int writeText(WINDOW*, const char*, ...);
int clearText(WINDOW*);
int setStatusBarText(WINDOW*, const char*);

#endif