#include <iostream>
using namespace std;

int main()
{

    int arr[10000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = 0, e = n - 1;

    int mid;

    // at least 2 elements are reqd
    while (s < e)
    {
        mid = (s + e) / 2;

        if (arr[mid] < arr[e])
        {
            e = mid;
        }

        else if (arr[mid] > arr[e])
            s = mid + 1;
    }

    // e-1 (or s-1) if we want the HIGHEST ELEMENT before the dropped
    // e (or s) if we want the MINIMUM ELEMENT making the drop
    cout << e - 1 << endl;
}