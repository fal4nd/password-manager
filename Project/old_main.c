#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define SIZE 50
#define PWDLEN 16

extern int errno;


struct record{
  char website[SIZE];
  char username[SIZE];
  char password[PWDLEN];
} typedef record;


void addPassword(record* line);

void generatePassword(char* password);

char generateChar();



int main(){
  srand(clock());
  FILE *fp;
  record line;

  if((fp = fopen("passwords.txt", "a")) == NULL){
    fprintf(stderr, "Value of errno: ", errno);
    exit(EXIT_FAILURE);
  }

  addPassword(&line);
  //printf("%s\n%s\n%s\n", line.website, line.username, line.password);

  fprintf(fp, "%s, %s, %s\n", line.website, line.username, line.password);

  fclose(fp);

  return 0;
}



void addPassword(record* line){
  printf("insert the website name: ");
  scanf("%s", line->website);

  printf("insert the username: ");
  scanf("%s", line->username);

  printf("do you want to choose or generate a password? c/G");
  char choose_or_generate[1];
  scanf("%s", &choose_or_generate);
  if(choose_or_generate[0] == 'c' || choose_or_generate[0] == 'C'){
    printf("digit the password: ");
    scanf("%s", line->password);
  }else{
    generatePassword(line->password);
  } 
  
}

void generatePassword(char* password){
  for(int i = 0; i < PWDLEN; i++){
    password[i] = generateChar();
  }
}

//generate randomly a alfanumerical character or a symbol
char generateChar(){
  int random_num = rand() % 100;

  switch(random_num){
    case 0 ... 24:    //generate upper case letter
      return((rand() % 26) + 65);
    case 25 ... 49:   //generate lower case letter
      return((rand() % 26) + 97);
    case 50 ... 84:   //generate number
      return((rand() % 10) + 48);
    case 85 ... 99:   //generate symbol
      return((rand() % 15) + 33);
  }
}
