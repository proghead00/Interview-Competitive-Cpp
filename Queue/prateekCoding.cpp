#include <vector>
#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main()
{

    int q, i;
    cin >> q; // no. of queries
    long int a, b;
    stack<long int> s;

    for (i = 0; i < q; i++)
    {
        cin >> a;
        if (a == 1)
        {
            if (s.empty())
                cout << "No Code\n";
            else
            {
                cout << "Ans: " << s.top() << "\n";
                s.pop();
            }
        }
        else
        {
            cin >> b;
            s.push(b);
        }
    }

    return 0;
}
