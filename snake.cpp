#include<iostream>
#include<locale>
#include<windows.h>
#include<stdio.h>
#include <string>
#include<conio.h>
#include <stdlib.h>
#include <thread>
#include <future>
using namespace std;


void matrice(string matrix[15][40]) {
	for (int i = 0; i <15; i++)
	{
		for (int j = 0; j <40; j++)
			matrix[i][j] = " ";
		matrix[i][0] = "#";
		matrix[i][39] = "#";
	}
        	
    	for (int i = 0; i < 40; i++)
	{
		matrix[0][i]="#";
		matrix[14][i]="#";
	}
	matrix[8][15]="x";
}


void stampa(string matrix[15][40])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 40; j++)
			cout << matrix[i][j];
		cout << endl;
	}
}


int colore ()
{
	string c;
	cout<<"inserisci il colore che desideri"<<endl;
	cin>> c;
	while(c!="nero"&&c!="blu"&&c!="verde"&&c!="cyano"&&c!="rosso"&&c!="viola"&&c!="giallo"&&c!="bianco"&&c!="grigio"&&c!="blufluo"&&c!="verdefluo"&&c!="cyanofluo"&&c!="rossofluo"&&c!="violafluo"&&c!="giallofluo")
	{
		cout<<"mi dispiace questo colore non è disponibile, inserirne un altro"<<endl;
		cin>>c;
	}
	if(c=="nero")
		return 0;
	if(c=="blu")
		return 1;
	if(c=="verde")
		return 2;
	if(c=="cyano")
		return 3;
	if(c=="rosso")
		return 4;
	if(c=="viola")
		return 5;
	if(c=="giallo")
		return 6;
	if(c=="bianco")
		return 7;
	if(c=="grigio")
		return 8;
	if(c=="blufluo")
		return 9;
	if(c=="verdefluo")
		return 10;
	if(c=="cyanofluo")
		return 11;
	if(c=="rossofluo")
		return 12;
	if(c=="violafluo")
		return 13;
	if(c=="giallofluo")
		return 14;
}
char inmossa()
{
	char mossa;
	if(cin>>mossa)
	return mossa;
}
void selector(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}
void movimento(string matrix[15][40], char mossa, int & x, int & y)
{
	for (int i = 0; i <15; i++)
	{
		for (int j = 0; j <40; j++)
			matrix[i][j] = " ";
       		matrix[i][0] = "#";
       		matrix[i][39] = "#";
	}
    	for (int i = 0; i < 40; i++)
	{
		matrix[0][i]="#";
		matrix[14][i]="#";
	}

	if(mossa=='w')
	{
		matrix[x-1][y]="x";
		x=x-1;
	}
	else if(mossa=='s')
	{
		matrix[x+1][y]="x";
		x++;
	}
	else if(mossa=='a')
	{
		matrix[x][y-1]="x";
		y=y-1;
	}
	else if(mossa=='d')
	{
		matrix[x][y+1]="x";
		y++;
	}
}

int main()
{
	int x=8,y=15;
	setlocale(LC_ALL,"");
	selector(colore());
	string campo[15][40];
	matrice(campo);
	stampa(campo);
	while(true)
	{
		using namespace std::literals;
		auto input = std::async(std::launch::async, inmossa);
		while (input.wait_for(0.1s) != std::future_status::ready)
		{
			system("cls");
			stampa(campo);
		}
		movimento(campo,input.get(),x, y);
	}
}
