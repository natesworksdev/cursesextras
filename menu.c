#include <ncurses.h>
#include <string.h>
#include "menu.h"

WINDOW* createWindow(int height, int width)
{
    initscr();
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    int start_y = (rows - height) / 2;
    int start_x = (cols - width) / 2;

    WINDOW* win = newwin(height, width, start_y, start_x);
    refresh();
    box(win, 0, 0);
    wrefresh(win);

    return win;
}

int setTitle(WINDOW* win, const char* title)
{
    wmove(win, 0, 1);
    wprintw(win, title);
    return OK;
}

int writeText(WINDOW* win, const char* fmt, ...)
{
    int max_y, y, max_x, x;
    getmaxyx(win, max_y, max_x);
    wmove(win, 1, 1);

    char text[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(text, sizeof(text), fmt, args);
    va_end(args);

    for (size_t i = 0; i < strlen(text); i++)
    {
        getyx(win, y, x);
        if (x >= max_x - 1 || text[i] == '\n') 
        {
            if (text[i] == '\n')
            {
                wmove(win, y + 1, 1);
            }
            else
            {
                wmove(win, y + 1, 0);
            }
        }
        else
        {
            waddch(win, text[i]);
        }
    }

    return OK;
}

int clearText(WINDOW* win)
{
    int height, width;
    getmaxyx(win, height, width);

    for (int y = 1; y < height - 1; ++y)
    {
        for (int x = 1; x < width - 1; ++x)
        {
            mvwaddch(win, y, x, ' ');
        }
    }

    wrefresh(win);
    return 0;
}

int setStatusBarText(WINDOW* win, const char* text)
{
    int height, width;
    getmaxyx(win, height, width);
    wmove(win, height - 1, 0);    
    waddstr(win, text);
    wrefresh(win);
}
