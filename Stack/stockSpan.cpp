#include <iostream>
#include <stack>
using namespace std;

void span(int arr[], int n)
{
    stack<int> s;
    s.push(0); //pushing the index

    cout << "1"
         << " ";

    for (size_t i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
            s.pop();

        int span = s.empty() ? i + 1 : i - s.top();

        cout << span << " ";

        s.push(i);
    }
}

int main()
{

    int arr[] = {60, 10, 20, 15, 35, 50};
    span(arr, 6);
}
