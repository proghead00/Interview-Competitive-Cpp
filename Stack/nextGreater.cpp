// Problem with the code: Output is always "-1"

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


vector<int> nextGreater(int arr[], int n)
{
    stack<int> s;
    vector<int> v;

    s.push(arr[n - 1]);
    cout << "-1"
         << " ";

    for (size_t i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        int nextG = (s.empty()) ? -1 : s.top();
        v.push_back(nextG);

        s.push(arr[i]);

    }

    // reverse(v.begin(), v.end());
    // return v;
}

int main()
{
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};

    vector<int> v1;
    v1 = nextGreater(arr, 8);

    for (auto i : v1)
        cout << i << " ";
}
