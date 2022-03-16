#include <iostream>
#include <stdlib.h>
#include <locale>
#include <thread>
#include <future>
using namespace std;


struct Partita {
	int punti;
	char matrix;
};


void riempiMatrice(string matrix[15][40])
{
for (int i = 1; i < 14; i++) 
{
        for (int j = 1; j < 39; j++)
            matrix[i][j] = " ";
}
for (int i = 0; i < 15; i++)
{
	matrix[i][0]="#";
	matrix[i][39]="#";
}
for (int i = 0; i < 40; i++)
{
	matrix[0][i]="#";
	matrix[14][i]="#";
}
matrix [8][15]="█";
}
char inmossa()
{
	char mossa;
	cin>>mossa;
	return mossa;
}
string movimento(string matrix[15][40], string mossa, int x, int y)
{
	if(mossa=="w")
		return matrix[x-1][y]="█";
	if(mossa=="s")
		return matrix[x+1][y]="█";
	if(mossa=="a")
		return matrix[x][y-1]="█";
	if(mossa=="d")
		return matrix[x][y+1]="█";
}
int main() 
{
	setlocale(LC_ALL,"");
	string campo[15][40];
	riempiMatrice(campo);
	string s;
	while(true)
	{
		using namespace std::literals;
		auto input = std::async(std::launch::async, inmossa);
		while (input.wait_for(0.1s) != std::future_status::ready)
		{
			for(int i=0; i<15; i++)
			{
				cout<<endl;
				for(int j=0; j<40; j++)
					cout<<campo[i][j];
			}
			s=inmossa();
			system ("cls");
		}
		movimento(campo, s, 8, 15);
	}
}