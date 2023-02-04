#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<cmath>
using std::abs;

const int GRIDSIZE = 7;

int gameBoard[7][7];
void userImput(int* userx_ptr, int* usery_ptr);
void HitOrMiss(int* userx, int* usery);
void DisplayBoard();
void GameRules();



int GameGrid[7][7] = { { 1,0,1,1,1,0,0 }, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0} };
int GameGrid2[7][7] = { { 1,0,1,1,1,0,0 }, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0} };

int Player1ShotGrid[7][7];
int Player2ShotGrid[7][7];


void control();
// char array for gamegrid 

// 0 water
// 1 ship
// 2 ship hit
// 3 ship miss

// add game rules


int main()
{
	int userx = 0;
	int usery = 0;
	int userx2 = 0;
	int usery2 = 0;
	GameRules();
	DisplayBoard();
	cout << endl;
	while (userx != 11)
	{
		userImput(&userx, &usery);
		HitOrMiss(&userx, &usery);
		
		DisplayBoard();
	}
	return 0;
}
void userImput(int *userx, int *usery)
{
	int test = 0;
	while (test==0)
	{
		cout << "Enter x coordinate " << endl;
		cin >> *userx;
		cout << "Enter y coordinate " << endl;
		cin >> *usery;

		if (*userx > 6 || *usery > 6)
		{
			cout << "Enter value less then 7" << endl;
			test = 0;
		}
		else
		{
			test = 1;
		}
		if (Player1ShotGrid[*userx][*usery] ==2 || Player1ShotGrid[*userx][*usery] == 3)
		{
			test = 0;
			cout << "Enter new value " << endl;
		}
		else
		{
			test = 1;
		}

	}
	
}
void control() {
	
	



}
void GameRules() {

	cout << "2 ship hit " << endl;
	cout << "3 ship miss " << endl<<endl;

}
void HitOrMiss(int* userx, int* usery)
{

		if (GameGrid[*userx][*usery] ==1)
		{
			cout << endl<<"hit"<<endl << endl;
			GameGrid[*userx][*usery] = 2;
			Player1ShotGrid[*userx][*usery] = 2;
		}
		else
		{
			cout <<endl<< "Miss"<<endl << endl;
			GameGrid[*userx][*usery] = 3;
			Player1ShotGrid[*userx][*usery] = 3;

		}
}
void DisplayBoard() 
{

	int numOfLoops = 0;
	int x = 0;
	int y = 0;

	for (int i = 0; i < (GRIDSIZE*GRIDSIZE); i++)
	{
		cout << Player1ShotGrid[x][y];
		y++;
		numOfLoops++;
		if (numOfLoops==7)
		{
			cout << endl;
			numOfLoops = 0;
			x++;
			y = 0;
		}

	}

}