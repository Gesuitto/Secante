#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;
// g++ snake.cpp -o snake.exe -std=c++2a


bool gameover(string matrix[20][20]) {
    bool controllo=true;
    for (int i = 0; i <19; i++)
    {
        for (int j = 0; j <19; j++)
        if(matrix[i][0] == "a" ||     matrix[i][19] == "a" || matrix[0][j]=="a" || matrix[19][j]=="a")
        {
            controllo=false;
        }
    }
    return controllo;
}


// Se colpisci una mela allora ritorni true
bool controllomela1(string campo[20][20], int riga, int colonna)
{
    if(campo[riga][colonna]=="O")
        return true;
    else
        return false;
}
void nuovamela(string campo[20][20])
{
    campo[rand()%18][rand()%18]="O";
    // campo[7][12]="O";
}


void movimento(string matrix[][20], char direzione, int & x, int & y)
{
    // Ripristino il bordo
    for (int i = 0; i <20; i++)
    {
        for (int j = 0; j <20; j++)
        {
            if(matrix[i][j]=="a")
                matrix[i][j]=" ";
        }
        matrix[i][0] = "#";
        matrix[i][19] = "#";
    }
    matrix[x][y] = " ";
    for (int i = 0; i < 20; i++)
    {
        matrix[0][i]="#";
        matrix[19][i]="#";
    }

    // Muovo a seconda della direzione
    if(direzione=='w')
    {
        x--;
        if(controllomela1(matrix, x, y)==true)
            nuovamela(matrix);
        matrix[x][y]="a";
    }
    else if(direzione=='s')
    {
        x++;
        if(controllomela1(matrix, x, y)==true)
            nuovamela(matrix);
        matrix[x][y]="a";
    }
    else if(direzione=='a')
    {
        y--;
        if(controllomela1(matrix, x, y)==true)
            nuovamela(matrix);
        matrix[x][y]="a";
    }
    else if(direzione=='d')
    {
        y++;
        if(controllomela1(matrix, x, y)==true)
            nuovamela(matrix);
        matrix[x][y]="a";
    }
}

string inputMossa() {
    string mossa;
    if (cin >> mossa)
        return mossa;
}


void stampa(string m[][20]) {
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++)
            cout << m[i][j];
        cout << endl;
    }
}


void cambiaDirezione(char & direzione, string mossa) {
    if (mossa == "w")
        direzione = 'w';
    else if (mossa == "s")
        direzione = 's';
    else if (mossa == "a")
        direzione = 'a';
    else if (mossa == "d")
        direzione = 'd';
}


int main()
{
    srand(time(NULL));
    string campo[20][20];
    int x=9;
    int y=9;
    char direzione='w'; // Variabile che ha il valore w quando si muove in alto, s quando si muove in basso, a quando si muove a sinistra, d quando si muove a destra
    for (int i = 0; i <20; i++)
    {
        for (int j = 0; j <20; j++)
            campo[i][j]=" ";
    }
    for(int i=0; i<20;i++)
    {
        campo[0][i]="#";
        campo[i][0]="#";
        campo[19][i]="#";
        campo[i][19]="#";
        campo[x][y]="a";
    }

    // Genero la prima mela
    nuovamela(campo);
    stampa(campo);
    string num;

    while(gameover(campo)==true) //cin
    {
    	// Eseguo la funzione inputMove in modo asincrono
	    auto input = std::async(std::launch::async, inputMossa);
        system("cls");
		using namespace std::literals;
		while (input.wait_for(0.2s) != std::future_status::ready) {
			movimento(campo, direzione, x, y);
            stampa(campo);
		}
		num = input.get(); // Assegnamo a num la variabile presa da inputMossa in maniera asincrona
        cambiaDirezione(direzione, num);
    }
    cout<<"gameover";   
}