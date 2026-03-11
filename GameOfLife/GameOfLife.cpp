#include <iostream>
#include <windows.h> 
#include <ctime>

using namespace std;

const int ROWS = 25;
const int COLMS = 50;

int CountNeighbors(char grid[ROWS][COLMS], int row, int col) {
    int count = 0;

    //проверяем верхнюю строку
    if (row > 0 && col > 0 && grid[row - 1][col - 1] == '#') count++;   //верхний-левый
    if (row > 0 && grid[row - 1][col] == '#') count++;  //верхний
    if (row > 0 && col < COLMS - 1 && grid[row - 1][col + 1] == '#') count++;   //верхний-правый

    //проверяем ту же строку
    if (col > 0 && grid[row][col - 1] == '#') count++;  //левый
    if (col < COLMS - 1 && grid[row][col + 1] == '#') count++;  //правый

    //проверяем нижнюю строку
    if (row < ROWS - 1 && col > 0 && grid[row + 1][col - 1] == '#') count++;    //нижний-левый
    if (row < ROWS - 1 && grid[row + 1][col] == '#') count++;   //нижний
    if (row < ROWS - 1 && col < COLMS - 1 && grid[row + 1][col + 1] == '#') count++;    //нижний-правый

    return count;
}

int main()
{
    srand(time(NULL));

    char grid[ROWS][COLMS];
    char newgrid[ROWS][COLMS];

    //заполяем случайными живыми клетками
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLMS; j++) {
            grid[i][j] = (rand() % 100 < 20) ? '#' : '.';
        }
    }

    while (true) {
        //выводим
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLMS; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLMS; j++) {
                int neighbors = CountNeighbors(grid, i, j);

                if (grid[i][j] == '#') {    //живая клетка
                    if (neighbors == 2 || neighbors == 3) {
                        newgrid[i][j] = '#';
                    }
                    else {
                        newgrid[i][j] = '.';
                    }
                }
                else {  //мертвая клетка
                    if (neighbors == 3) {
                        newgrid[i][j] = '#';
                    }
                    else {
                        newgrid[i][j] = '.';
                    }
                }
            }
        }

        //копируем новое поколение
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLMS; j++) {
                grid[i][j] = newgrid[i][j];
            }
        }
        Sleep(100);
        system("cls");
    }

    return 0;
}
