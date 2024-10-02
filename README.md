# Curses Extras

This is a small library providing simplified usage for the ncurses library in C. It simplifies the creation of windows, adding titles, writing formatted text, and managing a status bar. This is still in very early beta, you can use it in production but it doesn't add that many things.

### Functions

* **`WINDOW* createWindow(int height, int width)`** 
    * Creates a centered window with the given dimensions.
    * Initializes ncurses if not already done.
    * Returns a pointer to the created window.

* **`int setTitle(WINDOW* win, const char* title)`**
    * Sets the title of the window.
    * The title is displayed in the top border of the window.

* **`int writeText(WINDOW* win, const char* fmt, ...)`**
    * Writes formatted text to the window, similar to `printf`.
    * Handles newlines and automatically wraps text within the window boundaries.

* **`int clearText(WINDOW* win)`**
    * Clears the text content of the window.

* **`int setStatusBarText(WINDOW* win, const char* text)`**
    * Sets the text in the status bar at the bottom of the window.

### Usage

1. **Include the header file:**
```c
#include "menu.h"
```
2. **Link with ncurses library:**
```c
gcc your_program.c -o your_program -lncurses
```
3. **Use the functions in your code:**
```c
#include <ncurses.h>
#include "menu.h"

int main() {
    WINDOW* my_win = createWindow(10, 20);
    setTitle(my_win, "My Window");
    writeText(my_win, "Hello, %s!\nThis is a test.", "world");
    setStatusBarText(my_win, "Press any key to exit...");
    getch();
    endwin();
    return 0;
}
```
