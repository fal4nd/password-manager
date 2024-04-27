#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Initialize ncurses
  initscr();
  cbreak();  // Line buffering disabled, Pass on everything to me
  noecho();  // Don't echo() while we do getch

  // Get windows size
  int height, width;
  getmaxyx(stdscr, height, width);
  // mvprintw(10, 20, "height = %i, width = %i", height, width);
  
  // Print a message
  mvprintw(height / 2 - 2, width / 3, "Hello, this is your new password manager\n");
  mvprintw(height / 2 - 1, width * 0.4, "Inserisci la password");

  refresh();

  // Get the password
  char pwd[17];
  int dialog_height = 1;
  int pwd_length = 16;
  WINDOW *pwd_win = newwin(dialog_height, pwd_length, height / 2, width / 2 - 8);
  wmove(pwd_win, 0, 0);
  noecho();
  char * input_buffer = (char *) malloc(pwd_length);
  wgetnstr(pwd_win, input_buffer, 16);
  strncpy(pwd, input_buffer, pwd_length);
  pwd[pwd_length] = '\0';

  refresh();

  mvprintw(height / 2 - 1, width / 3, pwd);
  
  // Wait for a key press
  getch();



  // Clean up
  endwin();

  return 0;
}

