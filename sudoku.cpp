#include <bits/stdc++.h>

using namespace std;

#define N 9

//for finding unassigned location in sudoku
bool FindUnassignedLocation(int sudoku[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (sudoku[row][col] == 0)
                return true;
    return false;
}

// to check no. is present in that row [Left to Right]
bool UsedInRow(int sudoku[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (sudoku[row][col] == num)
            return true;
    }
    return false;
}

// to check no. is present in that col [Up to Down]
bool UsedInCol(int sudoku[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
    {
        if (sudoku[row][col] == num)
            return true;
    }
    return false;
}

//to check no. is present in that small box [3x3]
bool UsedInBox(int sudoku[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (sudoku[boxStartRow + row][boxStartCol + col] == num)
                return true;
        }
    }
    return false;
}

//to check no is safe to write at particular block
bool isSafe(int sudoku[N][N], int row, int col, int num)
{
    return !UsedInRow(sudoku, row, num) &&
           !UsedInCol(sudoku, col, num) &&
           !UsedInBox(sudoku, row - row % 3, col - col % 3, num);
}

//to solve sudoku
bool solvesudoku(int sudoku[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(sudoku, row, col))
        return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(sudoku, row, col, num))
        {
            sudoku[row][col] = num;
            if (solvesudoku(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

//to print solved sudoku
void print(int sudoku[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sudoku[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << " ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
}

int main()
{
    int sudoku[N][N];
    cout << "Enter unsolved sudoku : " << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> sudoku[i][j];

    cout << "\nUnsolved sudoku is : " << endl;
    print(sudoku);

    if (solvesudoku(sudoku) == true)
    {
        cout << "Solved sudoku is : " << endl;
        print(sudoku);
    }
    else
        cout << "No solution exist!!!";
    return 0;
}
/* Sample imput:  
    3 0 6 5 0 8 4 0 0
    5 2 0 0 0 0 0 0 0
    0 8 7 0 0 0 0 3 1
    0 0 3 0 1 0 0 8 0
    9 0 0 8 6 3 0 0 5
    0 5 0 0 9 0 6 0 0
    1 3 0 0 0 0 2 5 0
    0 0 5 2 0 6 3 0 0
    0 0 0 0 0 0 0 7 4
*/