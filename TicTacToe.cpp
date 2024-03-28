#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using std::cin;
using std::cout;
using std::string;

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

};

class Player
{
private:
string gameBoard[3][3];
 
public: 
  void playerTurn()
  {
    int x,y;
    
    
    {
      cout << "Choose row 1-3:";
        cin >> x;
      
      cout << "Choose column 1-3:";
        cin >> y;
      



    }
  }




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
using std::cin;
using std::cout;

int startPlayer;

Game newGame;
newGame.clearBoard();
newGame.showBoard();
startPlayer = newGame.startingPlayer();
if (startPlayer == 1)
      {
        cout << "You make the first move.";
      }
    else
      {
        cout << "CPU makes the first move.";
      } 

return 0;	
}
