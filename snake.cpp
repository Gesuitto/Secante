#include <ctime>
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
#include <csetjmp>
// g++ snake.cpp -o snake.exe -std=c++2a


using namespace std;
using namespace std::chrono;
std::jmp_buf my_jump_buffer;

struct game{
	int punteggio;
	int colore;
	std::chrono::duration<long double> difficolta;
	char personaggio;
};
void selector(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}
void regole()
{
	cout<<"Buongiorno, vuoi visualizzare  le regole del gioco?"<<endl;
	char testo;
	string regola;
	cin>>regola;

	if(regola=="si")
	{
		ifstream fin("prova202.txt");
	    while(fin.get(testo))
	    {
	    	cout<<testo;
		}
		fin.close();
	    srand(time(NULL));	
	}
	else if(regola=="no")
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
    cout<<"inserisci il colore che desideri tra i sottostanti"<<endl;
    selector(6);
    cout<<"giallo"<<endl;
    selector(14);
    cout<<"giallofluo"<<endl;
    selector(1);
    cout<<"blu"<<endl;
    selector(2);
    cout<<"verde"<<endl;
    selector(3);
    cout<<"cyano"<<endl;
    selector(4);
    cout<<"rosso"<<endl;
    selector(5);
    cout<<"viola"<<endl;
    selector(7);
    cout<<"bianco"<<endl;
    selector(8);
    cout<<"grigio"<<endl;
    selector(9);
    cout<<"blufluo"<<endl;
    selector(10);
    cout<<"verdefluo"<<endl;
    selector(11);
    cout<<"cyanofluo"<<endl;
    selector(12);
    cout<<"rossofluo"<<endl;
    selector(13);
    cout<<"fucsia"<<endl;
    selector(10);
    cout<<"r";selector(14);cout<<"a";selector(11);cout<<"n";selector(7);cout<<"d";selector(4);cout<<"o";selector(12);cout<<"m"<<endl;
    selector(7);
    cin>> c;
    while(c!="random"&&c!="blu"&&c!="verde"&&c!="cyano"&&c!="rosso"&&c!="viola"&&c!="giallo"&&c!="bianco"&&c!="grigio"&&c!="blufluo"&&c!="verdefluo"&&c!="cyanofluo"&&c!="rossofluo"&&c!="fucsia"&&c!="giallofluo")
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
    if(c=="random")
    	return rand()%14+1;
}

int gameover(char matrix[15][40], int &punteggio,char n) {
	string conferma;
    for (int i = 0; i <14; i++)
    {
        for (int j = 0; j <39; j++)
        if(matrix[i][0] == n ||     matrix[i][39] == n || matrix[0][j]== n || matrix[14][j] == n)
        {
        	if(punteggio>1){
	        	cout<<"SEI MORTO =( hai totalizzato un punteggio di "<<punteggio<<" punti"<<endl;
	        	cout<<"vuoi riprovare?"<<endl;
	        	cin>>conferma;
	        	while(conferma!="si"&&conferma!="no"){
	        		cout<<"errore inserimento"<<endl;
	        		cin>>conferma;
				}
	        	if(conferma=="si")
	        		std::longjmp(my_jump_buffer,0);
	        	else
	        		exit(EXIT_SUCCESS);
			}
			else
				cout<<"SEI MORTO =( hai totalizzato un punteggio di "<<punteggio<<" punto"<<endl;
				cout<<"vuoi riprovare?"<<endl;
	        	cin>>conferma;
	        	while(conferma!="si"&&conferma!="no"){
	        		cout<<"errore inserimento"<<endl;
	        		cin>>conferma;
				}
	        	if(conferma=="si")
	        		std::longjmp(my_jump_buffer,0);
	        	else
	        		exit(EXIT_SUCCESS);
				      
        }
    }
}
// Se colpisci una mela allora ritorni true
bool controllomela1(char campo[15][40], int riga, int colonna )
{
    if(campo[riga][colonna]=='@')
    {
        return true;
	}
    else
        return false;
}
void nuovamela(char campo[15][40])
{
    campo[rand()%13+1][rand()%38+1]='@';
    // campo[7][12]="O";
}
void calcolapunteggio( int &punteggio, char campo[15][40], int riga, int colonna )
{
	punteggio++;
}

void movimento(char matrix[][40], char direzione, int & x, int & y, int &punteggio,char n)
{
    // Ripristino il bordo
    for (int i = 0; i <15; i++)
    {
        for (int j = 0; j <40; j++)
        {
            if(matrix[i][j]=='a')
                matrix[i][j]=' ';
        }
        matrix[i][0] = '#';
        matrix[i][39] = '#';
    }
    matrix[x][y] = ' ';
    for (int i = 0; i <15; i++)
    {
        matrix[0][i]='#';
        matrix[14][i]='#';
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
        matrix[x][y]=n;
    }
    else if(direzione=='s')
    {
        x++;
        if(controllomela1(matrix, x, y)==true)
        {
        	nuovamela(matrix);
			calcolapunteggio(punteggio, matrix, x, y);	
		} 
        matrix[x][y]=n;
    }
    else if(direzione=='a')
    {
        y--;
        if(controllomela1(matrix, x, y)==true)
        {
        	nuovamela(matrix);
			calcolapunteggio(punteggio, matrix, x, y);	
		} 
        matrix[x][y]=n;
    }
    else if(direzione=='d')
    {
        y++;
        if(controllomela1(matrix, x, y)==true)
        {
        	nuovamela(matrix);
			calcolapunteggio(punteggio, matrix, x, y);	
		} 
        matrix[x][y]=n;
    }
}

char inputMossa() {
    char mossa;
    if (mossa=(char)_getch())
        return mossa;
}



void stampa(char m[][40]) {
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
 void matrice(char matrix[15][40]) {
    for (int i = 0; i <15; i++)
    {
        for (int j = 0; j <40; j++)
            matrix[i][j] = ' ';
        matrix[i][0] = '#';
        matrix[i][39] = '#';
    }
            
    for (int i = 0; i < 40; i++)
    {
        matrix[0][i]='#';
        matrix[14][i]='#';
    }
    matrix[8][15]='x';
}
std::chrono::duration<long double> tempo()
{
	setlocale(LC_ALL,"");
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
char nome(){
	char n;
	cout<<"scegli il tuo personaggio selezionando a tuo piacimento un carattere dalla tastiera"<<endl;
	cin>>n;
	return n;
}


int main()
{
    std::ios_base::sync_with_stdio(false); // Asincrono figo
	regole();
	setlocale(LC_ALL,"C");
	setjmp(my_jump_buffer);
	game partita;
    srand(time(NULL));
    std::cout << "\33[?25l"; // Nasconde il cursore
        
    char campo[15][40];
    int x=8,y=15;
    int controllo=10; // variabile creata per un ciclo infinito
    string inizio;	
    partita.punteggio=0;
    char nomegiocatore=nome();
    std::chrono::duration<long double> transizione =tempo();
	partita.colore=colore();
    selector(partita.colore); 
	partita.difficolta=transizione; 
    char direzione='d'; // Variabile che ha il valore w quando si muove in alto, s quando si muove in basso, a quando si muove a sinistra, d quando si muove a destra
    // Genero la prima mela
    matrice(campo);
    campo[8][20]='@';
    stampa(campo);
    string num;
    while(controllo=1)
    {
	    auto input = std::async(std::launch::async, inputMossa);
        std::cout << "\x1b[2J\x1b[1;1H"; // Pulisce lo schermo
		while (input.wait_for(partita.difficolta) != std::future_status::ready) {
			movimento(campo, direzione, x, y, partita.punteggio,nomegiocatore);
            stampa(campo);
            gameover(campo, partita.punteggio,nomegiocatore); 
		}
		num = input.get(); // Assegnamo a num la variabile presa da inputMossa in maniera asincrona
        cambiaDirezione(direzione, num);
 	}

}