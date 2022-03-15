#include <iostream>
#include <stdlib.h>
#include <locale>
using namespace std;


struct Partita {
	int punti;
	char matrix;
};


void riempiMatrice(char matrix[15][40])
{
	for (int i = 0; i <15; i++)
	{
        for (int j = 0; j <40; j++)
        	matrix[i][j] = ' ';
        matrix[i][0] = '#';
       	matrix[i][39] = '#';
    }
}


int main() 
{
	setlocale(LC_ALL,"");

	// Filippo è un c
}