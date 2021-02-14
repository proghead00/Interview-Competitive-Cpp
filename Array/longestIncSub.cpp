#include <bits/stdc++.h>

using namespace std;

int main()

{

    int n;
    cin >> n;
    int arr[n];

    int omax = 0;
    int lis[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int max = 0;

        for (int j = 0; j < i; j++)
        {

            if (arr[j] < arr[i])
            {
                if (lis[j] > max)
                {
                    max = lis[j];
                }
            }
        }

        lis[i] = max + 1;

        if (lis[i] > omax)
            omax = lis[i];
    }
    cout << omax;

    return 0;
}