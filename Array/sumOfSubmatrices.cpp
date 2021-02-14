#include <iostream>
using namespace std;

const int m = 2;
const int n = 2;

int sum(int arr[n][m])
{

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int top_left = (i + 1) * (j + 1);

            int bottom_right = (n - i) * (m - j);

            sum += (top_left * bottom_right) * (arr[i][j]);
        }
    }

    return sum;
}

int main()
{

    // int n;
    // cin >> n;

    // int m;
    // cin >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << sum(arr) << endl;
}