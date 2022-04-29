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
        if (matrix[0][i] == SNAKE || matrix[19][i] == SNAKE)
            return false;
    }
    return true;
}


bool appleCheck(string field[20][20], int x, int y) {
    return (field[x][y] == APPLE);
}


void addApple(string field[20][20], int x, int y) {
    int a, b;
    do {
        a = 1+rand()%17;
        b = 1+rand()%17;
    } while (a == x && b == y);
    field[a][b] = APPLE;
}


void move(string matrix[][20], char direction, int & x, int & y) {
    matrix[x][y] = " ";
    if (direction == 'w') {
        x--;
        if (appleCheck(matrix, x, y))
            addApple(matrix, x, y);
        matrix[x][y]=SNAKE;
    } else if (direction == 's') {
        x++;
        if(appleCheck(matrix, x, y))
            addApple(matrix, x, y);
        matrix[x][y]=SNAKE;
    } else if (direction == 'a') {
        y--;
        if(appleCheck(matrix, x, y))
            addApple(matrix, x, y);
        matrix[x][y]=SNAKE;
    } else if (direction == 'd') {
        y++;
        if(appleCheck(matrix, x, y))
            addApple(matrix, x, y);
        matrix[x][y]=SNAKE;
    }
}


string inputMove() {
    string move;
    if (cin >> move)
        return move;
}


void print(string m[][20]) {
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++)
            cout << m[i][j];
        cout << endl;
    }
}


void changeDirection(char & direction, string move) {
    if (move == "w")
        direction = 'w';
    else if (move == "s")
        direction = 's';
    else if (move == "a")
        direction = 'a';
    else if (move == "d")
        direction = 'd';
}


int main() {
    srand(time(NULL));
    string field[20][20];
    int x=9;
    int y=9;
    char direction='w';
    for (int i = 0; i <20; i++) {
        for (int j = 0; j <20; j++)
            field[i][j]=" ";
    }
    for (int i=0; i<20;i++) {
        field[0][i]=BORDER;
        field[i][0]=BORDER;
        field[19][i]=BORDER;
        field[i][19]=BORDER;
        field[x][y]=SNAKE;
    }

    addApple(field, x, y);
    print(field);

    while(gameover(field)) {
	    auto input = std::async(std::launch::async, inputMove);
		using namespace std::literals;
		while (input.wait_for(0.2s) != std::future_status::ready) {
			move(field, direction, x, y);
            print(field);
		}
        changeDirection(direction, input.get());
    }
}