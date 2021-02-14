#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char)

{

    char a[50];
    cin >> a;

    int i = 0;
    if (a[i] == '9')
    {
        i++;
    }

    for (; a[i] != '\0'; i++)
    {
        int digit = a[i] - '0';

        if (digit >= 5)
        {
            digit = 9 - digit;
            a[i] = digit + '0';
        }
    }
    cout << a << endl;
}