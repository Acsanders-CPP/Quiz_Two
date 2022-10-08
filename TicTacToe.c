// Allows for player versus play or player versus computer tic-tac-toe matches
#include <stdio.h>

//user interface for user navagation

void PrintBoard(char Slots[9]);
void PrintMainMenu();
void PvCMatch();
void PvPMatch();
void Quit();


int main(){
    PrintMainMenu();
}

void PrintBoard(char Slots[9]){
  printf("|%c|%c|%c|\n|%c|%c|%c|\n|%c|%c|%c|\n", Slots[0], Slots[1], Slots[2], Slots[3], Slots[4], Slots[5], Slots[6], Slots[7], Slots[8]);
}

void PrintMainMenu(){
  int input;
  
    printf("============================\nTic-Tac-Toe\n\n1.) Player vs. Player\n2.) Player vs. Computer\n3.) Quit\n============================\n\nEnter input:\n");

  scanf("%d", &input);

  switch (input){
    case 1:
      PvPMatch();
      break;

    case 2:
      PvCMatch();

    case 3:
      Quit();
  }
}

//match play code

void PvCMatch(){
  
}

//cpu match code

void PvPMatch(){
  int input;
  char Moves[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',};
  bool turn = true;

  while (true){
    PrintBoard(Moves);

    if(turn){
      turn = !turn;
    
      printf("Player 1's turn");

      while (true){
        scanf("%d", &input);

        if (Moves[i] == ' '){
          Moves[i] = 'X';

          break;
        }
        else{
          printf("Invalid Input");
        }
      }

    
    }else{
      turn = !turn;
    
      printf("Player 2's turn");

      scanf("%d", &input);
    }
  }
}

void Quit(){
  exit(0);
}