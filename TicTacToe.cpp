#include<iostream>

class GameBoard
{
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
  
  
  }	
}

void clearBoard();
void showBoard();
int checkOpenSpaces();
void playerTurn();
void cpuTurn();
char winnerCheck();
void showWinner();



int main(void)
{
using std::cin;
using std::cout;

char gameBoard[3][3];




	
	
	
	
	
return 0;	
}

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
	
	
}

int checkOpenSpaces()
{
	
	
}

void playerTurn()
{
	
	
}

void cpuTurn()
{
	
	
}

char winnerCheck()
{
	
	
}

void showWinner()
{
	
	
}