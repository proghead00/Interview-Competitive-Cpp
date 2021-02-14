#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{

    int T;
    cin >> T;

    while (T >= 1 && T <= 5)
    {
        int N;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + N);

        int x = 0, y = 1, z = N - 1;

        int s = 0;

        s = abs(arr[x] - arr[y]) + abs(arr[y] - arr[z]) + abs(arr[z] - arr[x]);

        cout << s << endl;

        T--;
    }
}