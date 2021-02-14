#include <iostream>
using namespace std;

void input2D(int mat[][10], int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }
}

void printSpiral(int mat[][10], int m, int n)
{
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = m - 1;

    while (left <= right || top <= bottom)
    {

        if (left <= right)
        {
            for (int i = top; i <= bottom; i++)
            {
                cout << mat[i][left] << ", ";
            }
            left = left + 1;
        }

        if (top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                cout << mat[bottom][i] << ", ";
            }
            bottom = bottom - 1;
        }

        if (left <= right)
        {
            for (int row = bottom; row >= top; row--)
            {
                cout << mat[row][right] << ", ";
            }
            right--;
        }

        if (top <= bottom)
        {
            for (int col = right; col >= left; col--)
            {
                cout << mat[top][col] << ", ";
            }
            ++top;
        }
    }

    cout << "END";
}

int main()
{
    int mat[10][10];
    int m, n;
    cin >> m >> n;
    input2D(mat, m, n);

    printSpiral(mat, m, n);
}
