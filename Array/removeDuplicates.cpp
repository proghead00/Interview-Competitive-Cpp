#include <iostream>
#include <cstring>
using namespace std;

// remove consecutive characters from a string
// cooding -> coding

void remove(char a[])
{

    int l = strlen(a);

    if (l == 0 or l == 1)
        return;

    int prev = 0;

    for (int current = 1; current < l; current++)
    {
        if (a[current] != a[prev])
        {
            prev++;
            a[prev] = a[current];
        }
    }
    a[prev + 1] = '\0';
    return;
}

int main(int argc, char)
{

    char a[100];
    cin.getline(a, 100);
    remove(a);
    cout << a << endl;
    return 0;
}