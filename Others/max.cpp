#include <iostream>
using namespace std;

int main()
{
    // your code goes here

    int N;
    cin >> N;

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int max2;

    // for (int i = 0; i < 10; i++)
    // {
    //     if (N % arr[i] == 0)
    //     {
    //         max2 = max(max2, arr[i]);
    //     }
    // }
    // cout << max2;

    for (int i = 1; i <= 10; i++)
    {
        if (N % i == 0)
            max2 = max(max2, i);
    }
    cout << max2;
    return 0;
}
