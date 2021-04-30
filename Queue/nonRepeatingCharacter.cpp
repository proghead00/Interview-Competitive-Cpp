#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> q;
    int freq[27] = {0};

    char ch;

    cin >> ch;

    while (ch != '.')
    {
        q.push(ch);

        freq[ch - 'a']++;

        while (!q.empty())
        {
            // a is mapped with 0, b with 1, and so on...
            int idx = q.front() - 'a';

            if (freq[idx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << endl;
                break;
            }
        }

        if (q.empty())
        {
            cout << "-1" << endl;
        }

        cin >> ch;
    }
}