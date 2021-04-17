#include <iostream>
#include <stack>
using namespace std;

int bar(int arr[], int n)
{

    stack<int> s;
    int res = 0;

    int t;
    int curr = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {

        // find prev smaller element
        while (s.empty() == false && arr[s.top() >= arr[i]])
        {
            t = s.top();
            s.pop();

            curr = arr[t] * (s.empty() ? i : (i - s.top() - 1));

            res = max(res, curr);
        }

        s.push(i);
    }

    // elements which do not have any smaller element on the right
    while (s.empty() == false)
    {
        t = s.top();
        s.pop();

        curr = arr[t] * (s.empty() ? n : (n - s.top() - 1));

        res = max(res, curr);
    }

    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << bar(arr, n) << endl;
}