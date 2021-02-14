#include <iostream>
using namespace std;

void readline(char a[], int maxlen, char delim = '\n')
{
    int i = 0;
    char ch = cin.get(); // first character

    while (ch != delim)
    {
        a[i] = ch;

        i++;

        if (i == (maxlen - 1))
        {
            break;
        }

        ch = cin.get();
    }

    a[i] = '\0';
}

int main()
{

    char a[100];
    // readline(a, 100, '$');

    cin.getline(a, 1000, '$');
    cout << a << endl;
    return 0;
}