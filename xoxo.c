#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <process.h>
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
COORD coord={0,0};

int board[9]={0,0,0,0,0,0,0,0,0};
int temp, turn, mode, move;
//player1=1 && player2=2 && comp=2
//move=1 for X && move=2 for O

void gotoxy (int x, int y);
void loading_screen();
char menu1();
char menu2();
void guide();
void ext();
void game_board();
void put_x (int x, int y);
void put_o (int x, int y);
void player_move();
void com_move();
void player1_first();
void player1_second();
void com_first();
void com_second();
int check_state();

int main () {
  system("cls");
  system("color e0");
  loading_screen();
  menu1();

  return 0;
}

void gotoxy (int x, int y) {
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loading_screen () {
  int i=0, j=0;

  Sleep(1000);
  printf ("\n");
  printf ("\t\tXXXXXXX       XXXXXXX       OOOOOOOOO       XXXXXXX       XXXXXXX       OOOOOOOOO      \n");
  printf ("\t\tX:::::X       X:::::X     OO:::::::::OO     X:::::X       X:::::X     OO:::::::::OO    \n");
  printf ("\t\tX:::::X       X:::::X  OO:::::::::::::OO    X:::::X       X:::::X   OO:::::::::::::OO  \n");
  printf ("\t\tX::::::X     X::::::X  O:::::::OOO:::::::O  X::::::X     X::::::X  O:::::::OOO:::::::O \n");
  printf ("\t\tXXX:::::X   X:::::XXX  O::::::O   O::::::O  XXX:::::X   X:::::XXX  O::::::O   O::::::O \n");
  printf ("\t\t   X:::::X X:::::X     O:::::O     O:::::O     X:::::X X:::::X     O:::::O     O:::::O \n");
  printf ("\t\t    X:::::X:::::X      O:::::O     O:::::O      X:::::X:::::X      O:::::O     O:::::O \n");
  printf ("\t\t     X:::::::::X       O:::::O     O:::::O       X:::::::::X       O:::::O     O:::::O \n");
  printf ("\t\t     X:::::::::X       O:::::O     O:::::O       X:::::::::X       O:::::O     O:::::O \n");
  printf ("\t\t    X:::::X:::::X      O:::::O     O:::::O      X:::::X:::::X      O:::::O     O:::::O \n");
  printf ("\t\t   X:::::X X:::::X     O:::::O     O:::::O     X:::::X X:::::X     O:::::O     O:::::O \n");
  printf ("\t\tXXX:::::X   X:::::XXX  O::::::O   O::::::O  XXX:::::X   X:::::XXX  O::::::O   O::::::O \n");
  printf ("\t\tX::::::X     X::::::X  O:::::::OOO:::::::O  X::::::X     X::::::X  O:::::::OOO:::::::O \n");
  printf ("\t\tX:::::X       X:::::X   OO:::::::::::::OO   X:::::X       X:::::X   OO:::::::::::::OO  \n");
  printf ("\t\tX:::::X       X:::::X     OO:::::::::OO     X:::::X       X:::::X     OO:::::::::OO    \n");
  printf ("\t\tXXXXXXX       XXXXXXX       OOOOOOOOO       XXXXXXX       XXXXXXX       OOOOOOOOO      \n");
  Sleep(1000);
  printf ("\t\t\t\t\t\t\t\t\t   __ _  __ _ _ __ ___   ___      \n");
  printf ("\t\t\t\t\t\t\t\t\t  / _` |/ _` | '_ ` _ \\ / _ \\   \n");
  printf ("\t\t\t\t\t\t\t\t\t | (_| | (_| | | | | | |  __/     \n");
  printf ("\t\t\t\t\t\t\t\t\t  \\__, |\\__,_|_| |_| |_|\\___|  \n");
  printf ("\t\t\t\t\t\t\t\t\t  |___/                           \n");
  Sleep(500);

  gotoxy(34,26);
  printf("Loading...");
  gotoxy(34,28);
  for (i=1; i<=43; i++) {
      for(j=0; j<=10000000; j++);
      printf("%c", 177);
  }
  gotoxy(34,26);
  printf("\r\t\t\t                                    ");
  gotoxy(34,28);
  printf("\r\t\t\t                                                                                 ");
  gotoxy(44,24);
  printf (YELLOW"Press any key to continue. . .");
  getch();
  }

char menu1() {
  system("cls");
  system("color e0");
  printf("\n\t\t\t\t            .---._   _.-''''-._   _.---.\n");
  printf("\t\t\t\t           :.---._`.:  .-   -.  ;.'_.---.;\n");
  printf("\t\t\t\t           :   '  `.':         .`.'  `   ;\n");
  printf("\t\t\t\t            `....-':'::. 0 0 .' :;`-....'\n");
  printf("\t\t\t\t                   :.:'_:---:_`::;\n");
  printf("\t\t\t\t           .--._   `:_(       )_:'   _.--.\n");
  printf("\t\t\t\t    .----.      ``-.'  \\     /  `.-''       .----.\n");
  printf("\t\t\t\t   :      :  .---'':    `-.-'    :--''''-. :      :\n");
  printf("\t\t\t\t___:      :____.--''`.    :    .'``--._____:      :_____\n");
  printf("\t\t\t\t   :   :_.'|  '    |  `''''|'''    |  `    `._;   :\n");
  printf("\t\t\t\t____`-'____|_______|_______|_______|_______|___`-'______\n");
  printf("\t\t\t\t      |       |     _ ___        __       |    |       |\n");
  printf("\t\t\t\t______|_______| |V||_| | |\\| |V||_ |\\|| | |____|_______|_\n");
  printf("\t\t\t\t |       |    | | || |_|_| | | ||__| ||_| |       |\n");
  printf("\t\t\t\t_|_______|____|___________________________|_______|______\n");
  printf("\t\t\t\t |                                                     |\n");
  printf("\t\t\t\t_|                                                     |_\n");
  printf("\t\t\t\t |                   1. ONE PLAYER GAME                | \n");
  printf("\t\t\t\t_|                   2. TWO PLAYERS GAME               |_\n");
  printf("\t\t\t\t |                   3. HOW TO PLAY                    |\n");
  printf("\t\t\t\t_|                   4. EXIT                           |_\n");
  printf("\t\t\t\t |                                                     |\n");
  printf("\t\t\t\t_|                                                     |_\n");
  printf("\t\t\t\t |                   SELECT 1/2/3/4                    |\n");
  printf("\t\t\t\t_|_____________________________________________________|_\n");
  printf("\t\t\t\t |       |       |       |       |       |       |\n");
  printf("\t\t\t\t_|_______|_______|_______|_______|_______|_______|_______\n");
  printf("\t\t\t\t    |       |       |       |       |       |       |\n");
  printf("\t\t\t\t____|_______|_______|_______|_______|_______|_______|_____\n");

  mode=0;

  switch (getch()) {
    fflush(stdin);
    case '1':
      mode=1;
      menu2();
    break;
    case '2':
      mode=2;
      menu2();
    break;
    case '3':
      system("cls");
      guide();
      return menu1();
    break;
    case '4':
      ext();
    break;
    default:
      printf ("\a");
      gotoxy(43,24);
      printf (RED"Please input the following selection !");
      Sleep (1000);
      return menu1();
    }
}

char menu2 () {
  system("cls");
  system("color e0");
  printf("\n\t\t\t\t            .---._   _.-''''-._   _.---.\n");
  printf("\t\t\t\t           :.---._`.:  .-   -.  ;.'_.---.;\n");
  printf("\t\t\t\t           :   '  `.':         .`.'  `   ;\n");
  printf("\t\t\t\t            `....-':'::. 0 0 .' :;`-....'\n");
  printf("\t\t\t\t                   :.:'_:---:_`::;\n");
  printf("\t\t\t\t           .--._   `:_(       )_:'   _.--.\n");
  printf("\t\t\t\t    .----.      ``-.'  \\     /  `.-''       .----.\n");
  printf("\t\t\t\t   :      :  .---'':    `-.-'    :--''''-. :      :\n");
  printf("\t\t\t\t___:      :____.--''`.    :    .'``--._____:      :_____\n");
  printf("\t\t\t\t   :   :_.'|  '    |  `''''|'''    |  `    `._;   :\n");
  printf("\t\t\t\t____`-'____|_______|_______|_______|_______|___`-'______\n");
  printf("\t\t\t\t      |       |     _ ___        __       |    |       |\n");
  printf("\t\t\t\t______|_______| |V||_| | |\\| |V||_ |\\|| | |____|_______|_\n");
  printf("\t\t\t\t |       |    | | || |_|_| | | ||__| ||_| |       |\n");
  printf("\t\t\t\t_|_______|____|___________________________|_______|______\n");
  printf("\t\t\t\t |                                                     |\n");
  printf("\t\t\t\t_|                                                     |_\n");
  printf("\t\t\t\t |                   1. PLAY WITH X                    | \n");
  printf("\t\t\t\t_|                   2. PLAY WITH O                    |_\n");
  printf("\t\t\t\t |                   3. BACK                           |\n");
  printf("\t\t\t\t_|                                                     |_\n");
  printf("\t\t\t\t |                                                     |\n");
  printf("\t\t\t\t_|                                                     |_\n");
  printf("\t\t\t\t |                    SELECT 1/2/3                     |\n");
  printf("\t\t\t\t_|_____________________________________________________|_\n");
  printf("\t\t\t\t |       |       |       |       |       |       |\n");
  printf("\t\t\t\t_|_______|_______|_______|_______|_______|_______|_______\n");
  printf("\t\t\t\t    |       |       |       |       |       |       |\n");
  printf("\t\t\t\t____|_______|_______|_______|_______|_______|_______|_____\n");

  if (mode==1) {
    switch (getch()) {
      fflush(stdin);
      case '1':
      com_second();
      break;
      case '2':
      com_first();
      break;
      case '3':
      return menu1();
      break;
      default:
      printf ("\a");
      gotoxy(43,24);
      printf (RED"Please input the following selection !");
      Sleep (1000);
      return menu2();
    }
  }
  else if (mode==2) {
    switch (getch()) {
      fflush(stdin);
      case '1':
      player1_first();
      break;
      case '2':
      player1_second();
      break;
      case '3':
      return menu1();
      break;
      default:
      printf ("\a");
      gotoxy(43,24);
      printf (RED"Please input the following selection !");
      Sleep (1000);
      return menu2();
    }
  }
}

void guide() {
    system ("cls");
		printf("\n\t\t\t\t   ____________________________________________________________\n");
    printf("\t\t\t\t / \\                                                           \\.\n");
    printf("\t\t\t\t|   |             |  |   _ \\ \\ \\      /  __ __| _ \\            |.\n");
    printf("\t\t\t\t \\_ |             __ |  (   | \\ \\ \\  /      |  (   |           |.\n");
    printf("\t\t\t\t    |            _| _| \\___/   \\_/\\_/      _| \\___/            |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    |                   _ \\ |       \\  \\ \\  /                  |.\n");
    printf("\t\t\t\t    |                   __/ |      _ \\  \\  /                   |.\n");
    printf("\t\t\t\t    |                  _|  ____| _/  _\\  _|                    |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    | ======================================================== |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    |                          |     |                         |.\n");
    printf("\t\t\t\t    |                       1  |  2  |  3                      |.\n");
    printf("\t\t\t\t    |                     _____|_____|_____                    |.\n");
    printf("\t\t\t\t    |                          |     |                         |.\n");
    printf("\t\t\t\t    |                       4  |  5  |  6                      |.\n");
    printf("\t\t\t\t    |                     _____|_____|_____                    |.\n");
    printf("\t\t\t\t    |                          |     |                         |.\n");
    printf("\t\t\t\t    |                       7  |  8  |  9                      |.\n");
    printf("\t\t\t\t    |                          |     |                         |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    | 1) This program has provided a 3x3 grid square board.    |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    | 2) Enter the number according to the number of square    |.\n");
    printf("\t\t\t\t    |    below to fill the square with 'X' or 'O'.             |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    | 3) Have first player go first, then the second player    |.\n");
    printf("\t\t\t\t    |    goes after it.                                        |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    | 4) The first player goes with 'X', while the second one  |.\n");
    printf("\t\t\t\t    |    goes with 'O'.                                        |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    | 5) Keep alternating moves until one of the players has   |.\n");
    printf("\t\t\t\t    |    won or until no one can win.                          |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    | 6) Player wins if it has drawn a row of three symbols.   |.\n");
    printf("\t\t\t\t    |                                                          |.\n");
    printf("\t\t\t\t    |               Press any key to go back. . .              |.\n");
    printf("\t\t\t\t    |   _______________________________________________________|___\n");
    printf("\t\t\t\t    |  /                                                          /.\n");
    printf("\t\t\t\t    \\_/__________________________________________________________/.\n");
    getch();
    fflush(stdin);
}

void ext() {
system("cls");
printf ("\n\n\n");
printf ("\t\t\t\t    ______                      __     ____                 \n");
printf ("\t\t\t\t   / ____  ____    ____    ____/ /    / __ )   __  __   ___  \n");
printf ("\t\t\t\t  / / __  / __ \\  / __ \\  / __  /    / __  |  / / / /  / _ \\ \n");
printf ("\t\t\t\t / /_/ / / /_/ / / /_/ / / /_/ /    / /_/ /  / /_/ /  /  __/ \n");
printf ("\t\t\t\t \\____/  \\____/  \\____/  \\__,_/    /_____/   \\__, /   \\___/  \n");
printf ("\t\t\t\t                                            /____/           \n");

    exit (1);
}

void game_board() {
  int y=0;

  for(y=5; y<=21; y++) {
    gotoxy(33,y);
    printf ("|         |");
  }

  gotoxy(24,10);
  printf ("-----------------------------");
  gotoxy(24,16);
  printf ("-----------------------------");

  gotoxy(28,7); printf("1");
  gotoxy(38,7); printf("2");
  gotoxy(48,7); printf("3");
  gotoxy(28,13); printf("4");
  gotoxy(38,13); printf("5");
  gotoxy(48,13); printf("6");
  gotoxy(28,19); printf("7");
  gotoxy(38,19); printf("8");
  gotoxy(48,19); printf("9");

  for(y=2; y<=24; y++) {
    gotoxy(58,y);
    printf ("|");
  }
}

void put_x (int x, int y) {
printf (RED);
  gotoxy(x,y);
printf (" _   _  \n");
  gotoxy(x,y+1);
printf ("( \\_/ )\n");
  gotoxy(x,y+2);
printf (" ) _ (  \n");
  gotoxy(x,y+3);
printf ("(_/ \\_)");
}

void put_o (int x, int y) {
printf (BLUE);
  gotoxy(x,y);
printf (" _____ \n");
  gotoxy(x,y+1);
printf ("/  _  \\\n");
  gotoxy(x,y+2);
printf ("| (_) | \n");
  gotoxy(x,y+3);
printf ("\\_____/ ");
}

void player_move (){
  int input;

retry:
  gotoxy(64,8);
  printf ("\x1b[0mInput number to fill the square:> ");
  printf ("\b  \b");
  scanf ("%d", &input);
  fflush (stdin);
  temp=input;

  if (input>0 && input<=9) {
    if (board[temp-1]==0){
      if (move==1) {
        switch (input) {
          case 1:
          put_x(25,5);
          break;
          case 2:
          put_x(35,5);
          break;
          case 3:
          put_x(45,5);
          break;
          case 4:
          put_x(25,11);
          break;
          case 5:
          put_x(35,11);
          break;
          case 6:
          put_x(45,11);
          break;
          case 7:
          put_x(25,17);
          break;
          case 8:
          put_x(35,17);
          break;
          case 9:
          put_x(45,17);
          break;
        }
      }
      else if (move==2) {
        switch (input) {
          case 1:
            put_o(25,5);
          break;
          case 2:
            put_o(35,5);
          break;
          case 3:
            put_o(45,5);
          break;
          case 4:
            put_o(25,11);
          break;
          case 5:
            put_o(35,11);
          break;
          case 6:
            put_o(45,11);
          break;
          case 7:
            put_o(25,17);
          break;
          case 8:
            put_o(35,17);
          break;
          case 9:
            put_o(45,17);
          break;
        }
      }
    }
    else {
      printf ("\a");
      gotoxy(64,8);
      printf (YELLOW"Square have been filled !                               ");
      Sleep(1500);
      goto retry;
    }
  }
  else {
    printf ("\a");
    gotoxy(64,8);
    printf (YELLOW"Can only enter numbers 1-9 !                            ");
    Sleep(1500);
    goto retry;
  }
}

void com_move() {
  int input;
retry:
  input=temp;

  if (board[temp-1]==0) {
    if (move==1) {
      switch (input) {
        case 1:
        put_x(25,5);
        break;
        case 2:
        put_x(35,5);
        break;
        case 3:
        put_x(45,5);
        break;
        case 4:
        put_x(25,11);
        break;
        case 5:
        put_x(35,11);
        break;
        case 6:
        put_x(45,11);
        break;
        case 7:
        put_x(25,17);
        break;
        case 8:
        put_x(35,17);
        break;
        case 9:
        put_x(45,17);
        break;
      }
    }
    else if (move==2) {
      switch (input) {
        case 1:
        put_o(25,5);
        break;
        case 2:
        put_o(35,5);
        break;
        case 3:
        put_o(45,5);
        break;
        case 4:
        put_o(25,11);
        break;
        case 5:
        put_o(35,11);
        break;
        case 6:
        put_o(45,11);
        break;
        case 7:
        put_o(25,17);
        break;
        case 8:
        put_o(35,17);
        break;
        case 9:
        put_o(45,17);
        break;
      }
    }
  }
  else {
    if (temp==9) {
      temp=temp-4;
      goto retry;
    }
    else {
      temp++;
      goto retry;
    }
  }
}

void player1_first() {

  system ("cls");
  game_board();

  for (turn=1; turn<=9; turn++) {
    if (turn%2==0){
      check_state();
      gotoxy(80,4);
      printf (BLUE"[ PLAYER_2 TURN ]");
      move=2;
      player_move();
      board[temp-1]=2;
    }
    else {
      check_state();
      gotoxy(80,4);
      printf (RED"[ PLAYER_1 TURN ]");
      move=1;
      player_move();
      board[temp-1]=1;
    }
  }
  check_state();
}

void player1_second() {

  system ("cls");
  game_board();

  for (turn=1; turn<=9; turn++) {
    if (turn%2==0){
      check_state();
      gotoxy(80,4);
      printf (BLUE"[ PLAYER_1 TURN ]");
      move=2;
      player_move();
      board[temp-1]=1;
    }
    else {
      check_state();
      gotoxy(80,4);
      printf (RED"[ PLAYER_2 TURN ]");
      move=1;
      player_move();
      board[temp-1]=2;
    }
  }
  check_state();
}

void com_first() {
  int n;
  system ("cls");
  game_board();


  for (turn=1; turn<=9; turn++) {
    if (turn%2==0){
      check_state();
      gotoxy(80,4);
      printf (BLUE"[ PLAYER_1 TURN ]");
      move=2;
      player_move();
      board[temp-1]=1;
    }
    else {
      check_state();
      gotoxy(80,4);
      printf (RED"[ COMPUTER TURN ]");
      Sleep(1200);

      if (board[0]+board[1]+board[2]+board[3]+board[4]+board[5]+board[6]+board[7]+board[8]==0) {
        put_x(35,11);
        goto jump;
      }

      for (n=0; n<=9; n=n+3) {
        if (board[n]+board[n+1]+board[n+2]==2 || board[n]+board[n+1]+board[n+2]==4) {
          if (board[n]== 0) { temp=n+1; }
          else if ( board[n+1]== 0 ) { temp=n+2; }
          else if ( board[n+2]== 0 ) { temp=n+3; }
        }
      }

      for (n=0; n<=3; n++) {
        if (board[n]+board[n+3]+board[n+6]==2 || board[n]+board[n+3]+board[n+6]==4) {
          if (board[n]== 0) { temp=n+1; }
          else if ( board[n+3]== 0 ) { temp=n+4; }
          else if ( board[n+6]== 0 ) { temp=n+7; }
        }
      }

      if (board[0]+board[4]+board[8]==2 || board[0]+board[4]+board[8]==4) {
        if (board[0]== 0) { temp=1; }
        else if ( board[4]== 0 ) { temp=5; }
        else if ( board[8]== 0 ) { temp=9; }
      }

      if (board[2]+board[4]+board[6]==2 || board[2]+board[4]+board[6]==4) {
        if (board[2]== 0) { temp=3; }
        else if ( board[4]== 0 ) { temp=5; }
        else if ( board[6]== 0 ) { temp=7; }
      }

      move=1;
      com_move();
      board[temp-1]=2;
      jump:
        board[4]=2;
    }
  }
  check_state();
}

void com_second() {
  int n;
  system ("cls");
  game_board();

  for (turn=1; turn<=9; turn++) {
    if (turn%2==0){
      check_state();
      gotoxy(80,4);
      printf (BLUE"[ COMPUTER TURN ]");
      Sleep(1200);

      for (n=0; n<=9; n=n+3) {
        if (board[n]+board[n+1]+board[n+2]==2 || board[n]+board[n+1]+board[n+2]==4) {
          if (board[n]== 0) { temp=n+1; }
          else if ( board[n+1]== 0 ) { temp=n+2; }
          else if ( board[n+2]== 0 ) { temp=n+3; }
        }
      }

      for (n=0; n<=3; n++) {
        if (board[n]+board[n+3]+board[n+6]==2 || board[n]+board[n+3]+board[n+6]==4) {
          if (board[n]== 0) { temp=n+1; }
          else if ( board[n+3]== 0 ) { temp=n+4; }
          else if ( board[n+6]== 0 ) { temp=n+7; }
        }
      }

      if (board[0]+board[4]+board[8]==2 || board[0]+board[4]+board[8]==4) {
        if (board[0]== 0) { temp=1; }
        else if ( board[4]== 0 ) { temp=5; }
        else if ( board[8]== 0 ) { temp=9; }
      }

      if (board[2]+board[4]+board[6]==2 || board[2]+board[4]+board[6]==4) {
        if (board[2]== 0) { temp=3; }
        else if ( board[4]== 0 ) { temp=5; }
        else if ( board[6]== 0 ) { temp=7; }
      }

      move=2;
      com_move();
      board[temp-1]=2;
    }
    else {
      check_state();
      gotoxy(80,4);
      printf (RED"[ PLAYER_1 TURN ]");
      move=1;
      player_move();
      board[temp-1]=1;
    }
  }
  check_state();
}

int check_state() {
  if(board[0]*board[1]*board[2]==1 || board[3]*board[4]*board[5]==1 || board[6]*board[7]*board[8]==1 || board[0]*board[3]*board[6]==1 || board[1]*board[4]*board[7]==1 || board[2]*board[5]*board[8]==1 || board[0]*board[4]*board[8]==1 || board[2]*board[4]*board[6]==1){
    Sleep (1500);
    system("cls");
    printf ("\n");
    printf ("\t\t\t\t    ____    __      ___  __  __  ______  ____     ___  \n");
    printf ("\t\t\t\t   / __ \\  / /     /   | \\ \\/ / / ____/ / __ \\   <  / \n");
    printf ("\t\t\t\t  / /_/ / / /     / /| |  \\  / / __/   / /_/ /   / / \n");
    printf ("\t\t\t\t / ____/ / /___  / ___ |  / / / /___  / _, _/   / / \n");
    printf ("\t\t\t\t/_/     /_____/ /_/  |_| /_/ /_____/ /_/ |_|   /_/ \n");
    printf ("\t\t\t\t             _       __   ____   _   __ \n");
    printf ("\t\t\t\t            | |     / /  /  _/  / | / / \n");
    printf ("\t\t\t\t            | | /| / /   / /   /  |/ / \n");
    printf ("\t\t\t\t            | |/ |/ /  _/ /   / /|  / \n");
    printf ("\t\t\t\t            |__/|__/  /___/  /_/ |_/ \n");

    for (turn=9; turn>=0; --turn) {
            board[turn]=0;
    }

    printf (YELLOW"\n\nPress any key to go back to Main Menu. . .");
    getch();
    fflush(stdin);
    return menu1();
  }
  else if (board[0]*board[1]*board[2]==8 || board[3]*board[4]*board[5]==8 || board[6]*board[7]*board[8]==8 || board[0]*board[3]*board[6]==8 || board[1]*board[4]*board[7]==8 || board[2]*board[5]*board[8]==8 || board[0]*board[4]*board[8]==8 || board[2]*board[4]*board[6]==8) {
    if (mode==1) {
      Sleep (1500);
      system("cls");
      printf("\n\n\n");
      printf("\t\t\t\t   ______ ____   __  ___ ____   __  __ ______ ______ ____ \n");
      printf("\t\t\t\t  / ____// __ \\ /  |/  // __ \\ / / / //_  __// ____ / __ \\   \n");
      printf("\t\t\t\t / /    / / / // /|_/ // /_/ // / / /  / / //  __/ / /_/ /  \n");
      printf("\t\t\t\t/ /___ / /_/ // /  / // ____// /_/ /  / / //  /__ / _, _/ \n");
      printf("\t\t\t\t\\____/ \\____//_/  /_//_/     \\____/  /_/ //_____//_/ |_|      \n");
      printf ("\t\t\t\t             _       __   ____   _   __ \n");
      printf ("\t\t\t\t            | |     / /  /  _/  / | / / \n");
      printf ("\t\t\t\t            | | /| / /   / /   /  |/ / \n");
      printf ("\t\t\t\t            | |/ |/ /  _/ /   / /|  / \n");
      printf ("\t\t\t\t            |__/|__/  /___/  /_/ |_/ \n");
    }
    else if (mode==2) {
      Sleep (1500);
      system("cls");
      printf ("\n\n\n");
      printf ("\t\t\t\t    ____    __      ___  __  __  ______  ____     ___ \n");
      printf ("\t\t\t\t   / __ \\  / /     /   | \\ \\/ / / ____/ / __ \\   |__ \\ \n");
      printf ("\t\t\t\t  / /_/ / / /     / /| |  \\  / / __/   / /_/ /   __/ / \n");
      printf ("\t\t\t\t / ____/ / /___  / ___ |  / / / /___  / _, _/   / __/ \n");
      printf ("\t\t\t\t/_/     /_____/ /_/  |_| /_/ /_____/ /_/ |_|   /____/ \n");
      printf ("\t\t\t\t             _       __   ____   _   __ \n");
      printf ("\t\t\t\t            | |     / /  /  _/  / | / / \n");
      printf ("\t\t\t\t            | | /| / /   / /   /  |/ / \n");
      printf ("\t\t\t\t            | |/ |/ /  _/ /   / /|  / \n");
      printf ("\t\t\t\t            |__/|__/  /___/  /_/ |_/ \n");
    }

    for (turn=9; turn>=0; --turn) {
            board[turn]=0;
    }

    printf (YELLOW"\n\nPress any key to go back to Main Menu. . .");
    getch();
    fflush(stdin);
    return menu1();
  }
  else if (turn > 9){
    Sleep (1500);
    system("cls");

    gotoxy (1,6);
    system("color e0");
    printf ("\t\t\t\t\t      ____    ____    ___   _       __ \n");
    printf ("\t\t\t\t\t     / __ \\  / __ \\  /   | | |     / / \n");
    printf ("\t\t\t\t\t    / / / / / /_/ / / /| | | | /| / / \n");
    printf ("\t\t\t\t\t   / /_/ / / _, _/ / ___ | | |/ |/ / \n");
    printf ("\t\t\t\t\t  /_____/ /_/ |_| /_/  |_| |__/|__/ \n");

    for (turn=9; turn>=0; --turn) {
            board[turn]=0;
    }

    printf (YELLOW"\n\nPress any key to go back to Main Menu. . .");
    getch();
    fflush(stdin);
    return menu1();
  }
}
