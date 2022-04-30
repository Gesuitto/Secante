#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <time.h>
// g++ snake.cpp -o snake.exe -std=c++2a
const char SNAKE = '$';
const char BORDER = '#';
const char APPLE = '0';


void gameover(char matrix[20][20]) {
    for (int i = 0; i <20; i++) {
        if (matrix[i][0] == SNAKE || matrix[i][19] == SNAKE || matrix[0][i] == SNAKE || matrix[19][i] == SNAKE) {
            std::cout << "Game over!" << std::endl;
            exit(0);
        }
    }
}


bool appleCheck(char field[20][20], int x, int y) {
    return (field[x][y] == APPLE);
}


void addApple(char field[20][20], int x, int y) {
    int a, b;
    do {
        a = 1+rand()%17;
        b = 1+rand()%17;
    } while (a == x && b == y);
    field[a][b] = APPLE;
}


void move(char matrix[][20], char direction, int & x, int & y) {
    matrix[x][y] = ' ';
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
    gameover(matrix);
}


std::string inputMove() {
    std::string move;
    if (std::cin >> move)
        return move;
}


void print(char m[][20]) {
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++)
            std::cout << m[i][j];
        std::cout << std::endl;
    }
}


void changeDirection(char & direction, std::string move) {
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
    char field[20][20];
    int x=9;
    int y=9;
    char direction='w';
    for (int i = 0; i <20; i++) {
        for (int j = 0; j <20; j++)
            field[i][j]=' ';
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

    while(true) {
	    auto input = std::async(std::launch::async, inputMove);
		using namespace std::literals;
		while (input.wait_for(0.2s) != std::future_status::ready) {
			move(field, direction, x, y);
            print(field);
		}
        changeDirection(direction, input.get());
    }
}