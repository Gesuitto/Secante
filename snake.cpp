#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;
// g++ snake.cpp -o snake.exe -std=c++2a
std::string SNAKE="$";
std::string BORDER="#";
std::string APPLE="0";


bool gameover(string matrix[20][20]) {
    for (int i = 0; i <20; i++) {
        if (matrix[i][0] == SNAKE || matrix[i][19] == SNAKE)
            return false;
    }
    for (int j = 0; j<20; j++) {
        if (matrix[0][j]==SNAKE || matrix[19][j]==SNAKE)
            return false;
    }
    return true;
}


bool appleCheck(string campo[20][20], int x, int y) {
    return (campo[x][y] == APPLE);
}


void addApple(string campo[20][20], int x, int y) {
    int a, b;
    do {
        a = 1+rand()%17;
        b = 1+rand()%17;
    } while (a == x && b == y);
    campo[a][b] = APPLE;
}


void movimento(string matrix[][20], char direzione, int & x, int & y) {
    for (int i = 0; i <20; i++) {
        for (int j = 0; j <20; j++) {
            if(matrix[i][j]==SNAKE)
                matrix[i][j]=" ";
        }
        matrix[i][0] = BORDER;
        matrix[i][19] = BORDER;
    }
    matrix[x][y] = " ";
    for (int i = 0; i < 20; i++)
    {
        matrix[0][i]=BORDER;
        matrix[19][i]=BORDER;
    }

    // Muovo a seconda della direzione
    if(direzione=='w') {
        x--;
        if(appleCheck(matrix, x, y)==true)
            addApple(matrix, x, y);
        matrix[x][y]=SNAKE;
    } else if(direzione=='s') {
        x++;
        if(appleCheck(matrix, x, y)==true)
            addApple(matrix, x, y);
        matrix[x][y]=SNAKE;
    } else if(direzione=='a') {
        y--;
        if(appleCheck(matrix, x, y)==true)
            addApple(matrix, x, y);
        matrix[x][y]=SNAKE;
    } else if(direzione=='d') {
        y++;
        if(appleCheck(matrix, x, y)==true)
            addApple(matrix, x, y);
        matrix[x][y]=SNAKE;
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


int main() {
    srand(time(NULL));
    string campo[20][20];
    int x=9;
    int y=9;
    char direzione='w'; // Variabile che ha il valore w quando si muove in alto, s quando si muove in basso, a quando si muove a sinistra, d quando si muove a destra
    for (int i = 0; i <20; i++) {
        for (int j = 0; j <20; j++)
            campo[i][j]=" ";
    }
    for(int i=0; i<20;i++) {
        campo[0][i]=BORDER;
        campo[i][0]=BORDER;
        campo[19][i]=BORDER;
        campo[i][19]=BORDER;
        campo[x][y]=SNAKE;
    }

    // Genero la prima mela
    addApple(campo, x, y);
    stampa(campo);
    string num;

    while(gameover(campo)==true) {
	    auto input = std::async(std::launch::async, inputMossa);
        system("cls");
		using namespace std::literals;
		while (input.wait_for(0.2s) != std::future_status::ready) {
			movimento(campo, direzione, x, y);
            stampa(campo);
		}
		num = input.get();
        cambiaDirezione(direzione, num);
    }
}