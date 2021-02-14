#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int a[][1000], int n)
{

    //rev each row
    for (int row = 0; row < n; row++)
    {
        int startcol = 0;
        int endcol = n - 1;

        while (startcol < endcol)
        {
            swap(a[row][startcol], a[row][endcol]);

            startcol++;
            endcol--;
        }
    }

    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

void rotate_stl(int a[][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        reverse(a[i], a[i + n]);
    }
    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

int main()
{

    int a[1000][1000];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    rotate_stl(a, n);
}