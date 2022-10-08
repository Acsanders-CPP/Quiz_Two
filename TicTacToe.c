// Allows for player versus play or player versus computer tic-tac-toe matches
#include <stdio.h>
#include <stdbool.h>

//user interface for user navagation

void CheckTieCondition(char Slots[9], bool Mode);
void CheckWinCondition(char Slots[9], bool Mode);
void PrintBoard(char Slots[9]);
void PrintMainMenu();
void PvCMatch();
void PvPMatch();
void Quit();
void Replay(bool Mode);


int main(){
    PrintMainMenu();
}

void CheckTieCondition(char Slots[9], bool Mode){
  int TieCount = 0;
  
  for (int i = 0; i  < 10; i += 4){
    if (i == 0){
      if ((Slots[i] != ' ') && ((Slots[i + 1] != Slots[i]) && (Slots[i + 1] != ' ')) || ((Slots[i + 3] != Slots[i]) && (Slots[i + 3] != ' '))){
        TieCount++;
      }
    }
    else if (i == 4){
      if((Slots[i] != ' ') && ((Slots[i - 3] != Slots[i]) && (Slots[i - 3] != ' ')) || ((Slots[i - 1] != Slots[i]) && (Slots[i - 1] != ' ')) || ((Slots[i - 4] != Slots[i]) && (Slots[i - 4] != ' ')) || ((Slots[i - 2] != Slots[i]) && (Slots[i - 2] != ' '))){
        TieCount++;
      }
    }
    else if (i == 8){
      if ((Slots[i] != ' ') && ((Slots[i - 3] != Slots[i]) && (Slots[i - 3] != ' ')) || ((Slots[i - 1] != Slots[i]) && (Slots[i - 1] != ' '))){
        TieCount++;
      }
    }
    printf("Tie Count: %d\n", TieCount);
  }

  if (TieCount == 3){
    PrintBoard(Slots);
    
    printf("Tie\n");

    Replay(Mode);
  }
}

void CheckWinCondition(char Slots[9], bool Mode){
  for (int i = 0; i  < 10; i += 4){
    if (i == 0){
      if ((Slots[i] == 'X' && Slots[i + 1] == 'X' && Slots[i + 2] == 'X') || (Slots[i] == 'X' && Slots[i + 3] == 'X' && Slots[i + 6] == 'X')){
        PrintBoard(Slots);
        
        printf("Player 1 wins\n");

        Replay(Mode);
      }
      else if ((Slots[i] == 'O' && Slots[i + 1] == 'O' && Slots[i + 2] == 'O') || (Slots[i] == 'O' && Slots[i + 3] == 'O' && Slots[i + 6] == 'O')){
        PrintBoard(Slots);
        
        printf("Player 2 wins\n");
        
        Replay(Mode);
      }
    }
    else if (i == 4){
      if((Slots[i] == 'X' && Slots[i - 3] == 'X' && Slots[i + 3] == 'X') || (Slots[i] == 'X' && Slots[i - 1] == 'X' && Slots[i + 1] == 'X') || (Slots[i] == 'X' && Slots[i - 4] == 'X' && Slots[i + 4] == 'X') || (Slots[i] == 'X' && Slots[i - 2] == 'X' && Slots[i + 2] == 'X')){
        PrintBoard(Slots);
        
        printf("Player 1 wins\n");
        
        Replay(Mode);
      }
      else if((Slots[i] == 'O' && Slots[i - 3] == 'O' && Slots[i + 3] == 'O') || (Slots[i] == 'O' && Slots[i - 1] == 'O' && Slots[i + 1] == 'O') || (Slots[i] == 'O' && Slots[i - 4] == 'O' && Slots[i + 4] == 'O') || (Slots[i] == 'O' && Slots[i - 2] == 'O' && Slots[i + 2] == 'O')){
        PrintBoard(Slots);
        
        printf("Player 2 wins\n");
        
        Replay(Mode);
      }
    }
    else if (i == 8){
      if ((Slots[i] == 'X' && Slots[i -  3] == 'X' && Slots[i - 6] == 'X') || (Slots[i] == 'X' && Slots[i - 1] == 'X' && Slots[i - 2] == 'X')){
        PrintBoard(Slots);
        
        printf("Player 1 wins\n");
        
        Replay(Mode);
      }
      else if ((Slots[i] == 'O' && Slots[i -  3] == 'O' && Slots[i - 6] == 'O') || (Slots[i] == 'O' && Slots[i - 1] == 'O' && Slots[i - 2] == 'O')){
        PrintBoard(Slots);
        
        printf("Player 2 wins\n");
        
        Replay(Mode);
      }
    }
  }
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

//cpu match code

void PvCMatch(){
  
}
//match play code

void PvPMatch(){
  int input;
  char Moves[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',};
  bool turn = true;

  while (true){
    PrintBoard(Moves);

    if(turn){
      turn = !turn;
    
      printf("Player 1's turn. Enter a number (1 -9):\n");

      while (true){
        scanf("%d", &input);

        if (Moves[input - 1] == ' '){
          Moves[input - 1] = 'X';

          CheckWinCondition(Moves, true);

          CheckTieCondition(Moves, true);

          break;
        }
        else{
          printf("Invalid Input\n");
        }
      }

    
    }else{
      turn = !turn;
    
      printf("Player 2's turn. Enter a number (1 -9):\n");

      while (true){
        scanf("%d", &input);

        if (Moves[input - 1] == ' '){
          Moves[input - 1] = 'O';

          CheckWinCondition(Moves, true);

          CheckTieCondition(Moves, true);

          break;
        }
        else{
          printf("Invalid Input\n");
        }
      }
    }
  }
}

void Quit(){
  exit(0);
}

void Replay(bool Mode){
  char input;

  printf("Play again? (y/n)\n");

  while (true){
    while ((getchar()) != '\n'){
    };
      
    scanf("%c", &input);

    if (tolower(input) == 'y'){
      if (Mode){
        PvPMatch();
      }
      else{
        PvCMatch();
      }
    }
    else if(tolower(input) == 'n'){
      exit(0);
    }
    else{
      printf("Invalid input\n");
    } 
  }
}