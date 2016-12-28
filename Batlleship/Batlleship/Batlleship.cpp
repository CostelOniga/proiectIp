// Batlleship.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using namespace std;
struct matrix {
	unsigned int values[10][10];
};
matrix matricePlayer;
matrix matriceComputer;
void initializare(matrix &mat)
{
	for (int index = 0; index < 10; index++)
	{
		for (int index2 = 0; index2 < 10; index2++)
		{
			mat.values[index][index2] = 0;
		}
	}
}
void afisare(marix matriceComputer, matricePlayer)
{

}

int main()
{
	initializare(matricePlayer);
	initializare(matriceComputer);
    return 0;
}

