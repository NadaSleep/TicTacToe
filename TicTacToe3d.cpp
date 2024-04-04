/*
Tyler Sexton
Lab 9
TicTacToe game
*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>

using namespace std;

class TicTacToe
{
private:
char gameBoard[3][3];

public:
  char playerSymbol,cpuSymbol;
//Creates the board and assigns a symbol to the player and cpu
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

//Shows the current state of the board  
void showBoard()
  {
    for (int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if (gameBoard[i][j] == ' ') 
        {
          cout << '*';
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

//Decides who goes first
  int startingPlayer()
  {
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNumber = rand() % 2;
    return randomNumber;
  }

//Checks to see if there is a winner
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
	  if(gameBoard[0][i] != '*' && gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
	  {

	    return gameBoard[0][i];
	  }
	}
//diagonals	
    if(gameBoard[0][0] != '*' && gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])	
    {
      return gameBoard[0][0];
	} 	
    if(gameBoard[0][2] != '*' && gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0]) 
    {
	  return gameBoard[0][2];
	}
return ' ';    
  }

//Players turn
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


//Keeps track of open spaces
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

//Handles the CPU turn
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

//The game if cpu goes first
  void cpuPlay()
  {
    char winner;
    int remainingSpaces;
    
    do {
    cpuTurn();
    showBoard();
    remainingSpaces = checkOpenSpaces(); 
	winner = winnerCheck();
    if (winner != ' ')
     {	
    cout << "The winner is " << winner << endl;    
    break;
    }
    if ( winner == ' ' && remainingSpaces == 0)
    {
    cout << "Tie game!" << endl;
    break;
	}
    playerTurn();
    showBoard();
    winner = winnerCheck();
    }
    while (true);
  }

//The game if player goes first
  void humanPlay()
  {
    char winner;
    int remainingSpaces;
    
	do {
    showBoard();
    playerTurn();
    showBoard();
    remainingSpaces = checkOpenSpaces();
    winner = winnerCheck();
    if (winner != ' ')
    {	
    cout << "The winner is " << winner << endl;    
    break;
    }
    if ( winner == ' ' && remainingSpaces == 0)
    {
    cout << "Tie game!" << endl;
    break;
	}
    cpuTurn();
    winner = winnerCheck();
    }
    while (true);
  }
};

class TicTacToeThreeD : public TicTacToe
{ private:
  char gameBoard3d[3][3][3];
  
  void TicTacToe3D(char playerSymbol,char cpuSymbol)
  {
	for(int i = 0; i < 3; i++)
    {
	  for (int j = 0; j < 3; j++)   
		
		for(int k = 0; k < 3; k++)
  	    {
          gameBoard3d[i][j][k] = '*';
        }
    }
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

//Assigns symbol to the cpu
if(playerSymbol == 'x' || playerSymbol == 'X'){
  cpuSymbol = 'O';
}
else {
  cpuSymbol = 'X';
}

cin.get();
system("cls");

//New game object
TicTacToe newGame(playerSymbol,cpuSymbol);

//Depending on who goes first the game method is called
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
