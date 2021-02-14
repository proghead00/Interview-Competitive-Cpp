#include <iostream>
#include <cstring>
using namespace std;

bool isPal(char a[])
{
    int i = 0;
    int j = strlen(a) - 1; //last character

    while (i < j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }

        else
        {
            return false;
        }
    }

    return true;
}

int main()
{

    char a[100];

    cin.getline(a, 100);

    if (isPal(a))
    {
        cout << "Palindrome string" << endl;
    }

    else
        cout << "Not a palindrome string";
}