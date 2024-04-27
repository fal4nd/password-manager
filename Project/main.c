#include <curses.h>
#define NCURSES_NOMACROS
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PWD_LEN 17
#define SIZE 50

struct record {
  char website[SIZE];
  char username[SIZE];
  char password[PWD_LEN];
} typedef record;


void login(int max_height, int max_width, char *password){
  // create login window
  WINDOW *login_window = newwin(7, 18, max_height / 2 - 3, max_width / 2 - 9);
  box(login_window, 0, 0);
  mvwprintw(login_window, 1, 1, "Password manager");
  mvwprintw(login_window, 3, 2, "Digit password");
  wmove(login_window, 5, 2);
  wrefresh(login_window);

  //get input password
  int i = 0;
  char ch = 0;
  char buffer[PWD_LEN];
  noecho();
  
  do{
    wrefresh(login_window);
    ch = getch();
    if(ch >= 32 && ch <= 126){
      buffer[i] = ch;
      mvwprintw(login_window, 5, 2 + i, "*");
    }else{
      --i;
    }
  }while(i++ < PWD_LEN - 2 && ch != '\0' && ch != '\n'); 
  buffer[i] = '\0';
  strncpy(password, buffer, i);
  //clear window
  werase(login_window);
  wrefresh(login_window);
  delwin(login_window);
}

void read_password(){

}

char generate_char(){
  int random_num = rand() % 100;

  switch(random_num){
    case 0 ... 24:  //print lower case letter
      return ((rand() % 26) + 65);
    case 25 ... 49: //print upper case letter
      return ((rand() % 26) + 97);
    case 50 ... 84: //print number
      return ((rand() % 10) + 48);
    case 85 ... 99: //print special character
      return ((rand() % 15) + 33);
  }
}

void generate_password(char *password){
  for(int i = 0; i < PWD_LEN - 1; i++){
    password[i] = generate_char();
  }
  password[PWD_LEN - 1] = '\0';
}

void add_password(){

}

void delete_password(){

}

void menu(int max_height, int max_width){
  WINDOW *menu_window = newwin(max_height, max_width, 0, 0);
  char *options[] = { "Read saved passwords" , "Add new password" , "Change password" , "Delete saved password"};
  int num_options = sizeof(options) / sizeof(options[0]);
  int choice = 0;
  int menu_ch;
  curs_set(0);
  
  while(1){
    // Print menu
    wclear(menu_window);
    box(menu_window, 0, 0);
    mvwprintw(menu_window, max_height / 2, max_width / 2, "%i", choice);
    for(int i = 0; i < num_options; i++){
      if(i == choice){
        wattron(menu_window, A_REVERSE);
        mvwprintw(menu_window, 1 + i, 1, options[i]);
        wattroff(menu_window, A_REVERSE);
      }else{
        mvwprintw(menu_window, 1 + i, 1, options[i]);
      }
    }
    wrefresh(menu_window);
    menu_ch = getch();
    // Menu movement
    switch(menu_ch){
      case 258:
      case 'k':
        if(choice < num_options - 1){
          choice += 1;
        }
        break;
      case 259:
      case 'j':
        if(choice > 0){
          choice -= 1;
        }
        break;
      default:
        break;
    }
    if(menu_ch == 10){
      break;
    }
  }
  delwin(menu_window);
}



int main(){
  int max_height, max_width;
  char password[PWD_LEN];
  srand(clock());

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  getmaxyx(stdscr, max_height, max_width);
  refresh();

  login(max_height, max_width, password);

  menu(max_height, max_width);

  getch();
  endwin();
  return 0;
}
