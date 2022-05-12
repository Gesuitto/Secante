#include <ctime>
#include <locale>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <thread>
#include<iostream>
#include <future>
#include <chrono>
#include <fstream> 
using namespace std;
using namespace std::chrono;
struct game{
	int punteggio;
	int colore;
	std::chrono::duration<long double> difficolta;
};
void regole()
{
	cout<<"Buongiorno, digita s se vuoi visualizzare le regole del gioco, n se le conosci già"<<endl;
	char testo;
	string regola;
	cin>>regola;

	if(regola=="s")
	{
		ifstream fin("prova202.txt");
	    while(fin.get(testo))
	    {
	    	cout<<testo;
		}
		fin.close();
	    srand(time(NULL));	
	}
	else if(regola=="n")
		{
		cout<<"visto che conosci già le regole cominciamo con il gioco"<<endl;
		}
		else
		{
			cout<<"errore di inserimento"<<endl;
			regole();			
		}

	
}
int colore ()
{
    string c;
    cout<<"inserisci il colore che desideri"<<endl;
    cin>> c;
    while(c!="blu"&&c!="verde"&&c!="cyano"&&c!="rosso"&&c!="viola"&&c!="giallo"&&c!="bianco"&&c!="grigio"&&c!="blufluo"&&c!="verdefluo"&&c!="cyanofluo"&&c!="rossofluo"&&c!="fucsia"&&c!="giallofluo")
    {
        cout<<"mi dispiace questo colore non è disponibile, inserirne un altro"<<endl;
        cin>>c;
    }
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
    if(c=="fucsia")
        return 13;
    if(c=="giallofluo")
        return 14;
}
void selector(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}
int gameover(string matrix[15][40], int &punteggio) {
    for (int i = 0; i <14; i++)
    {
        for (int j = 0; j <39; j++)
        if(matrix[i][0] == "x" ||     matrix[i][39] == "x" || matrix[0][j]=="x" || matrix[14][j]=="x")
        {
            cout<<"SEI MORTO =( hai totalizzato un punteggio di"<<" "<<punteggio<<"punti"<<endl;
            exit(EXIT_SUCCESS);          
        }
    }
}
// Se colpisci una mela allora ritorni true
bool controllomela1(string campo[15][40], int riga, int colonna )
{
    if(campo[riga][colonna]=="@")
    {
        return true;
	}
    else
        return false;
}
void nuovamela(string campo[15][40])
{
    campo[rand()%13+1][rand()%38+1]="@";
    // campo[7][12]="O";
}
void calcolapunteggio( int &punteggio, string campo[15][40], int riga, int colonna )
{
	punteggio++;
}

void movimento(string matrix[][40], char direzione, int & x, int & y, int &punteggio)
{
    // Ripristino il bordo
    for (int i = 0; i <15; i++)
    {
        for (int j = 0; j <40; j++)
        {
            if(matrix[i][j]=="a")
                matrix[i][j]=" ";
        }
        matrix[i][0] = "#";
        matrix[i][39] = "#";
    }
    matrix[x][y] = " ";
    for (int i = 0; i <15; i++)
    {
        matrix[0][i]="#";
        matrix[14][i]="#";
    }

    // Muovo a seconda della direzione
    if(direzione=='w')
    {
        x--;
        if(controllomela1(matrix, x, y)==true)
        {
        	nuovamela(matrix);
			calcolapunteggio(punteggio, matrix, x, y);	
		} 
        matrix[x][y]="x";
    }
    else if(direzione=='s')
    {
        x++;
        if(controllomela1(matrix, x, y)==true)
        {
        	nuovamela(matrix);
			calcolapunteggio(punteggio, matrix, x, y);	
		} 
        matrix[x][y]="x";
    }
    else if(direzione=='a')
    {
        y--;
        if(controllomela1(matrix, x, y)==true)
        {
        	nuovamela(matrix);
			calcolapunteggio(punteggio, matrix, x, y);	
		} 
        matrix[x][y]="x";
    }
    else if(direzione=='d')
    {
        y++;
        if(controllomela1(matrix, x, y)==true)
        {
        	nuovamela(matrix);
			calcolapunteggio(punteggio, matrix, x, y);	
		} 
        matrix[x][y]="x";
    }
}

char inputMossa() {
    char mossa;
    if (mossa=(char)_getch())
        return mossa;
}



void stampa(string m[][40]) {
    system("cls");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 40; j++)
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
    else if(mossa=="p")
    	system("pause");
}
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
std::chrono::duration<long double> tempo()
{
	string nome;
	cout<<"scegli la difficoltà tra facile, medio e difficile"<<endl;
	cin>>nome;
	while(nome!="facile"&&nome!="medio"&&nome!="difficile")
	{
		cout<<"mi dispiace ma questa difficoltà è inesistente"<<endl;
		cin>>nome;
	}
		if(nome=="facile")
			return 0.5s;
		if(nome=="medio")
			return 0.2s;
		if(nome=="difficile")
			return 0.05s;
}



int main()
{
	regole();
	setlocale(LC_ALL,"");
	game partita;
    srand(time(NULL));
    partita.colore=colore();
    selector(partita.colore);    
    string campo[15][40];
    int x=8,y=15;
    int controllo=10; // variabile creata per un ciclo infinito
    string inizio;	
    partita.punteggio=0;
    std::chrono::duration<long double> transizione =tempo(); 
	partita.difficolta=transizione; 
    char direzione='d'; // Variabile che ha il valore w quando si muove in alto, s quando si muove in basso, a quando si muove a sinistra, d quando si muove a destra
    // Genero la prima mela
    matrice(campo);
    campo[8][20]="@";
    stampa(campo);
    string num;
    while(controllo=1)
    {
	    auto input = std::async(std::launch::async, inputMossa);
        system("cls");
		while (input.wait_for(partita.difficolta) != std::future_status::ready) {
			movimento(campo, direzione, x, y, partita.punteggio);
            stampa(campo);
            gameover(campo, partita.punteggio); 
		}
		num = input.get(); // Assegnamo a num la variabile presa da inputMossa in maniera asincrona
        cambiaDirezione(direzione, num);
 	}

}