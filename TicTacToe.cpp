#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>

using namespace std;

class TicTacToe
{
private:
char gameBoard[3][3];
char playerSymbol,cpuSymbol;
public:
  TicTacToe(char playerSymbol,char cpuSymbol) : playerSymbol(playerSymbol),cpuSymbol(cpuSymbol)
  {
	for(int i = 0; i < 3; i++)
    {
	  for(int j = 0; j < 3; j++)
  	  {
        gameBoard[i][j] = '*';
      }
    }

  }
  
void showBoard()
  {
    for (int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if (gameBoard[i][j] == ' ') 
        {
          cout << '0';
        }
        else 
        {
          cout << gameBoard[i][j];
        }
        cout << "";
      }  
      cout << endl;
    } 
   cout << endl;
  }

  int startingPlayer()
  {
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNumber = rand() % 2;
    return randomNumber;
  }

  char winnerCheck()
  {
//rows    
	for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard[i][0] != '*' && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2])
	  {
	  	return gameBoard[i][0];
	  }
	
	}
//columns  	
  	for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard[i][0] != '*' && gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
	  {
	    return gameBoard[0][i];
	  }
	}
//diagonals	
    if(gameBoard[0][0] != '*' && gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])	
    {
      return gameBoard[0][0];
	} 	
    if(gameBoard[0][0] != '*' && gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0]) 
    {
	  return gameBoard[0][2];
	}
return ' ';    
  }

  void playerTurn()
  {
    int x,y;
    
    do
    {
      cout << "Choose row 1-3:\n";
        cin >> x;
      
      cout << "Choose column 1-3:\n";
        cin >> y;
    
      x--;
      y--;      

	  if (gameBoard[x][y] != '*')  
      {
	    cout << "Please choose an open space.";
      }
      else
      { 
        gameBoard[x][y] = playerSymbol;
	    break;	
	  }
    }
    while (gameBoard[x][y] != ' '); 
  }


  int checkOpenSpaces()
  {
    int openSpaces = 9;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++) 
      {
        if (gameBoard[i][j] != '*')
        { 
          openSpaces--;
        }  
      }
    } 
  return openSpaces;
  }


  void cpuTurn()
  {
    int x,y;
    if(checkOpenSpaces() > 0)
    {
      do
      {
        x = rand() % 3;
        y = rand() % 3;
      }
      while (gameBoard[x][y] != '*');
      gameBoard[x][y] = cpuSymbol;
    }
  }



//void showWinner();

  void cpuPlay()
  {
    char winner;
    
    do {
    cpuTurn();
    showBoard();
    winner = winnerCheck();
    if (winner != ' ')
    {
     break;
    }
    playerTurn();
    showBoard();
    winner = winnerCheck();
    }
    while (true);
  }

  void humanPlay()
  {
    char winner;
    
    do {
    showBoard();
    playerTurn();
    showBoard();
    winner = winnerCheck();
    if (winner != ' ')
    {
      break;
    }
    cpuTurn();
    showBoard();
    winner = winnerCheck();
    }
    while (true);
  }
};

int main(void)
{

int startPlayer;
char playerSymbol,cpuSymbol;

cout << "Tic Tac Toe game\n";
cout << "Choose a row and column to mark your spot. Mark three in a row by line or diagonal and you win.\n";
cout << "\nPress enter to continue:";
cin.get();
system("cls");

cout <<"Would you like to be X or O:";
cin >> playerSymbol;

if(playerSymbol == 'x' || playerSymbol == 'X'){
  cpuSymbol = 'O';
}
else {
  cpuSymbol = 'X';
}

cin.get();
system("cls");

TicTacToe newGame(playerSymbol,cpuSymbol);

startPlayer = newGame.startingPlayer();
if (startPlayer == 1)
      {
        cout << "You have first turn.\n";
        newGame.humanPlay();
      }
    else
      {
        cout << "CPU has first turn.\n";         
        newGame.cpuPlay();
      }

return 0;	
}
