#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char)
{

    string a;
    cin >> a;
    cout << a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (isupper(a[i]))
        {
            cout << endl;
            cout << a[i];
            // continue;
        }
        else
        {
            cout << a[i];
        }
    }
}