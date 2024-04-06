/*
Tyler Sexton
Lab 10
3D TicTacToe game
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
  TicTacToe(){}
  
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



//New class for a 3D TTT game

class TicTacToe3D : public TicTacToe
{ 
  
  private:
  char winner;
  int openSpaces;
  int xScore = 0;
  int oScore = 0;

  public:
  char gameBoard3D[3][3][3];
  
  TicTacToe3D(char playerSymbol,char cpuSymbol) : TicTacToe(playerSymbol,cpuSymbol)
  {
	for(int x = 0; x < 3; x++)
    {
	  for (int y = 0; y < 3; y++) 
      {
        for(int z = 0; z < 3; z++)
  	    {
          gameBoard3D[x][y][z] = '*';
        }
      }
    }
  }

//Shows the current state of the board in 3D 
  void showBoard3D()
  {
    for (int x = 0; x < 3; x++)
    {
      for(int y = 0; y < 3; y++)
      {
        for(int z = 0; z < 3; z++)  
       {
          if (gameBoard3D[x][y][z] == ' ') 
          {
           cout << '*';
          }
           else 
          {
            cout << gameBoard3D[x][y][z];
          }
        cout << " ";
       }  
      cout << endl;
    } 
   cout << endl;
  }
}
//Checks open space 3D
  int checkOpenSpaces3D()
  {
    int openSpaces = 27;
    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++) 
      {
        for (int z = 0; z < 3; z++)
		{
		  if (gameBoard3D[x][y][z] != '*')
          { 
            openSpaces--;
          }  
        }
      } 
    }
  return openSpaces;
}


//Players turn 3D
  void playerTurn3D()
  {
    int x,y,z;
    
    do
    {
      cout << "Choose Board 1-3:\n";
        cin >> x;
      
      cout << "Choose Row 1-3:\n";
        cin >> y;
      
      cout << "Choose Column 1-3:\n";
        cin >> z;
      
      x--;
      y--;
	  z--;      

	  if (gameBoard3D[x][y][z] != '*')  
      {
	    cout << "Please choose an open space.";
      }
      else
      { 
        gameBoard3D[x][y][z] = playerSymbol;
	    break;	
	  }
    }
    while (gameBoard3D[x][y][z] != '*'); 
  }
//cpu 3D Turn
  void cpuTurn3D()
  {
    int x,y,z;
    //if(checkOpenSpaces() > 0)
//    {
      do
      {
        x = rand() % 3;
        y = rand() % 3;
        z = rand() % 3;
      }
      while (gameBoard3D[x][y][z] != '*');
      gameBoard3D[x][y][z] = cpuSymbol;
//    }
  }


//Checks to see if there is a winner
  void winnerCheck3D()
{
//rows board 1    
	for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard3D[0][i][0] != '*' && gameBoard3D[0][i][0] == gameBoard3D[0][i][1] && gameBoard3D[0][i][0] == gameBoard3D[0][i][2])
	  {
	  char point = toupper(gameBoard3D[0][i][0]);
      if (point == 'X')
        {
          xScore++;
        } 
	    else
        {
          oScore++;
        }
	  }
	
	}
//row board 2
	for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard3D[1][i][0] != '*' && gameBoard3D[1][i][0] == gameBoard3D[1][i][1] && gameBoard3D[1][i][0] == gameBoard3D[1][i][2])
	  {
      char point = toupper(gameBoard3D[1][i][0]);
      if (point == 'X')
        {
          xScore++;
        }  
	    else
        {
          oScore++;
        }
	  }
	
	}
//row board 3
	for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard3D[2][i][0] != '*' && gameBoard3D[2][i][0] == gameBoard3D[2][i][1] && gameBoard3D[2][i][0] == gameBoard3D[2][i][2])
	  {
      char point = toupper(gameBoard3D[2][i][0]);
      if (point == 'X')
        {
          xScore++;
        } 
	    else
        {
          oScore++;
        }
	  }
	}

//columns board 1	
  	for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard3D[0][0][i] != '*' && gameBoard3D[0][0][i] == gameBoard3D[0][1][i] && gameBoard3D[0][0][i] == gameBoard3D[0][2][i])
	  {
      char point = toupper(gameBoard3D[0][0][i]);
      if (point == 'X')
        {
          xScore++;
        } 
	    else
        {
          oScore++;
        }
	  }
	}
//columns board 2
    for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard3D[1][0][i] != '*' && gameBoard3D[1][0][i] == gameBoard3D[1][1][i] && gameBoard3D[1][0][i] == gameBoard3D[1][2][i])
	  {
      char point = toupper(gameBoard3D[1][0][i]);
      if (point == 'X')
        {
          xScore++;
        } 
	    else
        {
          oScore++;
        }
	  }
	}
//columns board 3
    for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard3D[2][0][i] != '*' && gameBoard3D[2][0][i] == gameBoard3D[2][1][i] && gameBoard3D[2][0][i] == gameBoard3D[2][2][i])
	  {
      char point = toupper(gameBoard3D[2][0][i]);
      if (point == 'X')
        {
          xScore++;
        } 
	    else
        {
          oScore++;
        }
	  }
	}

//diagonals board 1
    if(gameBoard3D[0][0][0] != '*' && gameBoard3D[0][0][0] == gameBoard3D[0][1][1] && gameBoard3D[0][0][0] == gameBoard3D[0][2][2])	
    {
      char point = toupper(gameBoard3D[0][0][0]);
      if (point == 'X')
      {
        xScore++;
      } 
	  else
      {
        oScore++;
      }
    } 	
    if(gameBoard3D[0][0][2] != '*' && gameBoard3D[0][0][2] == gameBoard3D[0][1][1] && gameBoard3D[0][0][2] == gameBoard3D[0][2][0]) 
    {
	  char point = toupper(gameBoard3D[0][0][2]);
      if (point == 'X')
      {
        xScore++;
      } 
	  else
      {
        oScore++;
      }
	}

//diagonals board 2
    if(gameBoard3D[1][0][0] != '*' && gameBoard3D[1][0][0] == gameBoard3D[1][1][1] && gameBoard3D[1][0][0] == gameBoard3D[1][2][2])	
    {
      char point = toupper(gameBoard3D[1][0][0]);
      if (point == 'X')
      {
        xScore++;
      } 
	  else
      {
        oScore++;
      }
	} 	
    if(gameBoard3D[1][0][2] != '*' && gameBoard3D[1][0][2] == gameBoard3D[1][1][1] && gameBoard3D[1][0][2] == gameBoard3D[1][2][0]) 
    {
	  char point = toupper(gameBoard3D[1][0][2]);
      if (point == 'X')
      {
        xScore++;
      } 
	  else
      {
        oScore++;
      }
	}
//diagonals board 3
    if(gameBoard3D[2][0][0] != '*' && gameBoard3D[2][0][0] == gameBoard3D[2][1][1] && gameBoard3D[2][0][0] == gameBoard3D[2][2][2])	
    {
      char point = toupper(gameBoard3D[2][0][0]);
      if (point == 'X')
      {
        xScore++;
      } 
	  else
      {
        oScore++;
      }
	} 	
    if(gameBoard3D[2][0][2] != '*' && gameBoard3D[2][0][2] == gameBoard3D[2][1][1] && gameBoard3D[2][0][2] == gameBoard3D[2][2][0]) 
    {
	  char point = toupper(gameBoard3D[2][0][2]);
      if (point == 'X')
      {
        xScore++;
      } 
	  else
      {
        oScore++;
      }
	}

//rows 3d
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if(gameBoard3D[0][i][j] != '*' && gameBoard3D[0][i][j] == gameBoard3D[1][i][j] && gameBoard3D[0][i][j] == gameBoard3D[2][i][j])
        {
          char point = toupper(gameBoard3D[0][i][j]);
          if (point == 'X')
          {
            xScore++;
          }   
	      else
          {
            oScore++;
          }
        }
      }  
    }

//diagonal 3d 1
    if(gameBoard3D[0][0][0] != '*' && gameBoard3D[0][0][0] == gameBoard3D[1][1][1] && gameBoard3D[0][0][0] == gameBoard3D[2][2][2])	
    {
      char point = toupper(gameBoard3D[0][0][0]);
      if (point == 'X')
      {
        xScore++;
      } 
	  else
      {
        oScore++;
      }
	} 	
//diagonal 3d 2
    if(gameBoard3D[0][0][2] != '*' && gameBoard3D[0][0][2] == gameBoard3D[1][1][1] && gameBoard3D[0][0][2] == gameBoard3D[2][2][0])	
    {
      char point = toupper(gameBoard3D[0][0][2]);
      if (point == 'X')
      {
        xScore++;
      } 
	  else
      {
        oScore++;
      }
	} 	  
  }

//Player goes first in 3D game
  void humanPlay3D()
  {
    do 
    {
    showBoard3D();
    playerTurn3D();
    cout << "-----" << endl;
    showBoard3D();
    openSpaces = checkOpenSpaces3D(); 
    if (openSpaces > 0)
    {
      cout << "----- CPU TURN" << endl;
      cpuTurn3D();
      openSpaces = checkOpenSpaces3D();
    }  
  } while (openSpaces > 0);
    winnerCheck3D();
    cout << "The player with the most points wins!" << endl;
    cout << "-X Points: " << xScore << " -O Points: " << oScore << endl;
}

//CPU goes first in 3D game
  void cpuPlay3D()
  {
    do {
    cpuTurn3D();
    showBoard3D();    
    openSpaces = checkOpenSpaces3D();
    if (openSpaces > 0)
    {      
      playerTurn3D();
      showBoard3D();
      cout << "----- CPU TURN" << endl;
      openSpaces = checkOpenSpaces3D();
    }

  } while (openSpaces > 0);
    winnerCheck3D();
    cout << "The player with the most points wins!" << endl;
    cout << "-X Points: " << xScore << " -O Points: " << oScore << endl;
 }
};

int main(void)
{
int startPlayer;
char playerSymbol,cpuSymbol;

cout << "3D Tic Tac Toe game\n";
cout << "Now in 3D you must choose a board, row, and column to mark your spot. Mark three in a row by line or diagonal and you win.\n";
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

//New game object for 3D TTT
TicTacToe3D newGame(playerSymbol,cpuSymbol);

//Depending on who goes first the game method is called
startPlayer = newGame.startingPlayer();
if (startPlayer == 1)
      {
        cout << "You have first turn.\n";
        newGame.humanPlay3D();
      }
    else
      {
        cout << "CPU has first turn.\n";         
        newGame.cpuPlay3D();
      }

return 0;	
}
