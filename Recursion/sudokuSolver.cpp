#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canPlace(int mat[9][9], int i, int j, int n, int number)
{
    for (int x = 0; x < n; x++)
    {
        //row and column check
        if (mat[x][j] == number || mat[i][x] == number)
        {
            return false;
        }
    }

    // starting point of subgrid
    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;

    for (int x = sx; x < sx + rn; x++)
    {
        for (int y = sy; y < sy + rn; y++)
        {
            if (mat[x][y] == number)
            {
                return false;
            }
        }
    }
    return true;
}

//(i,j)th cell
// n -> size of grid

bool solver(int mat[][9], int i, int j, int n)
{
    //base case
    if (i == n)
    {
        //print the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    //case: row end
    if (j == n)
    {
        return solver(mat, i + 1, 0, n);
    }

    // skip the already filled cells
    if (mat[i][j] != 0)
    {
        return solver(mat, i, j + 1, n);
    }

    // rec case
    // fill the current cell w/ possible options
    for (int number = 1; number <= n; number++)
    {
        if (canPlace(mat, i, j, n, number))
        {

            // assume it's the correct num
            mat[i][j] = number;

            // call on remaining matrix
            bool couldPlace = solver(mat, i, j + 1, n);

            if (couldPlace == true)
            {
                return true;
            }
        }
    }

    //backtrack
    mat[i][j] = 0;
    return false;
}

int main()
{
    int mat[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solver(mat, 0, 0, 9);
}