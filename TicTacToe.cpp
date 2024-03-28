#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>

using namespace std;

const char player = 'X';
const char cpu = 'O';

class Game
{
private:
string gameBoard[3][3];

public:
  void clearBoard()
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
  	  {
        gameBoard[i][j] = "";
      }
    }

  }
  
  void showBoard()
  {
//  cout << ""
  cout << "|_____|_____|_____|"<<'\n';
//  cout << ""
  cout << "|_____|_____|_____|"<<'\n';
//  cout << ""
  cout << "|     |     |     |"<<'\n';
  }	

  int startingPlayer()
  {
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNumber = rand() % 2;
    return randomNumber;
  }

  string winnerCheck()
  {
//rows    
	for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][2] == gameBoard[i][0])
	  {
	  	return gameBoard[i][0];
	  }
	
	}
//columns  	
  	for(int i = 0; i < 3; i++)
  	{
	  if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
	  {
	    return gameBoard[0][i];
	  }
	}
//diagonals	
    if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])	
    {
      return gameBoard[0][0];
	} 	
    if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0]) 
    {
	  return gameBoard[0][2];
	}
return "";    
  }

};

class Player
{
private:
string gameBoard[3][3];
 
public: 
  void playerTurn()
  {
    int x,y;
    
    do
    {
      cout << "Choose row 1-3:";
        cin >> x;
      
      cout << "Choose column 1-3:";
        cin >> y;
    
	  if (gameBoard[x][y]!="")  
      {
	    cout << "Please choose an open space.";
      }
      else
      { 
        gameBoard[x][y] = player;
	    break;	
	  }
    }
    while (gameBoard[x][y] != ""); 
  }

  //void cpuTurn()
  



};



//void clearBoard();
//void showBoard();
int checkOpenSpaces();
void playerTurn();
void cpuTurn();
char winnerCheck();
void showWinner();



int main(void)
{

int startPlayer;

cout << "Tic Tac Toe game\n";
cout << "Choose a row and column to mark your spot. Mark three in a row by line or diagonal and you win.\n";
cout << "\nPress enter to continue:";
cin.get();
system("cls");

Game newGame;

startPlayer = newGame.startingPlayer();
if (startPlayer == 1)
      {
        cout << "You have first turn.\n";
      }
    else
      {
        cout << "CPU has first turn.\n";
      }

cout << "\nPress enter to start game.";

cin.get();

system("cls");

newGame.clearBoard();
newGame.showBoard();
 

return 0;	
}
