#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int freq[100] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'A']++;
    }

    int maxVal = 0;
    char maxChar;

    for (int i = 0; i < 100; i++)
    {
        if (freq[i] != 0)
        {
            if (freq[i] > maxVal)
            {
                maxVal = freq[i];
                maxChar = i + 'A';
            }
        }
    }
    cout << maxChar << endl;
    return 0;
}