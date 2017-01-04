// Batlleship.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
struct matrix {
	char values[10][10];
};
matrix board;

void initMatrix(matrix &mat)
{
	for (int index = 0; index < 10; index++)
	{
		for (int index2 = 0; index2 < 10; index2++)
		{
			mat.values[index][index2] ='0';
		}
	}
}
int check(matrix mat, int lineS,int columnS,int dimension)
{
	int caz =-1;
	for (int index = columnS; index < columnS + dimension; index++)
	{
		if (mat.values[lineS][index] != '0')
			caz = 0;
	}
	if (caz == -1)
		return 1;
	caz = -1;
	for (int index = lineS; index < lineS + dimension; index++)
	{
		if (mat.values[index][columnS] != '0')
			caz = 1;
	}
	if (caz == -1)
		return 2;
	caz = -1;
	if (columnS - dimension >= 0)
	{
		for (int index = columnS - dimension; index < columnS; index++)
		{
			if (mat.values[lineS][index] != '0')
				caz = 1;
		}
		if (caz == -1)
			return 3;
	}
	caz = -1;
	if (lineS - dimension >= 0)
	{
		for (int index = lineS - dimension; index < lineS; index++)
		{
			if (mat.values[index][columnS] != '0')
				caz = 1;
		}
		if (caz ==-1)
			return 4;
	}
	if (caz == 1)
		return 0;
}
void autoSet(matrix &board)
{
	unsigned int numberOfShips = 10;
	unsigned int dimensionOfShip = 1;
	 int index = 9;
	while (index >=0)
	{
		if (index < 4)
		{
			int x = rand() % 10;
			int y = rand() % 10;
			if (board.values[x][y] == '0')
			{
				board.values[x][y] = 'S';
				index--;
			}
		}
		if (index < 7 && index>3)
		{
			dimensionOfShip = 2;
			int x = rand() % 10;
			int y = rand() % 10;
			int caz;
			if (board.values[x][y] == '0')
			{
				caz = check(board, x, y, dimensionOfShip);
				if (caz == 1)
				{
					board.values[x][y] = board.values[x][y + 1] = 'N';
					index--;
				}
				if (caz == 2)
				{
					board.values[x][y] = board.values[x + 1][y] = 'N';
					index--;
				}
				if (caz == 3)
				{
					board.values[x][y] = board.values[x][y - 1] = 'N';
					index--;
				}
				if (caz == 4)
				{
					board.values[x][y] = board.values[x - 1][y] = 'N';
					index--;
				}
			}
		}
		if (index > 6 && index < 9)
			{
				dimensionOfShip = 3;
				int x = rand() % 10;
				int y = rand() % 10;
				int caz;
				if (board.values[x][y] == '0')
				{
					caz = check(board, x, y, dimensionOfShip);
					if (caz == 1)
					{
						board.values[x][y] = board.values[x][y + 1] = board.values[x][y + 2] = 'N';
						index--;
					}
					if (caz == 2)
					{
						board.values[x][y] = board.values[x + 1][y] = board.values[x + 2][y] = 'N';
						index--;
					}
					if (caz == 3)
					{
						board.values[x][y] = board.values[x][y - 1] = board.values[x][y - 2] = 'N';
						index--;
					}
					if (caz == 4)
					{
						board.values[x][y] = board.values[x - 1][y] = board.values[x - 2][y] = 'N';
						index--;
					}

				}
			}
		if(index==9)
		{ 
			int x = rand() % 10;
			int y = rand() % 10;
			int caz;
			if(board.values[x][y]=='0')
			{ 
				dimensionOfShip = 4;
				caz = check(board, x, y, dimensionOfShip);
				if (caz == 1)
				{
					board.values[x][y] = board.values[x][y + 1] = board.values[x][y + 2] = board.values[x][y + 3] = 'P';
					index--;
				}
				if (caz == 2)
				{
					board.values[x][y] = board.values[x + 1][y] = board.values[x + 2][y] = board.values[x + 3][y] = 'P';
					index--;
				}
				if (caz == 3)
				{
					board.values[x][y] = board.values[x][y - 1] = board.values[x][y - 2] = board.values[x][y - 3] = 'P';
					index--;
				}
				if (caz == 4)
				{
					board.values[x][y] = board.values[x - 1][y] = board.values[x - 2][y] = board.values[x - 3][y] = 'P';
					index--;
				}
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	initMatrix(board);
	autoSet(board);
	for (int i = 0; i <10; i++)
	{
		for (int j = 0; j <10; j++)
			cout << board.values[i][j] << " ";
		cout << endl;
	}
	int p;
	cin >> p;
	return 0;
}
