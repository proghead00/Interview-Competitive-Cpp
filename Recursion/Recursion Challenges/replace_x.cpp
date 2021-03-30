#include <iostream>
using namespace std;

void replacex(string s, int i)
{
    int c = 0;
    if (i == s.size())
    {
        return;
    }

    if (s[i] != 'x')
    {
        cout << s[i];
        replacex(s, i + 1);
    }
    else
    {
        c++;
        replacex(s, i + 1);
    }

    for (int j = 0; j < c; j++)
        cout << 'x';
}

int main()
{
    replacex("axxxxxxbxc", 0);
}
