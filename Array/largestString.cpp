#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char)
{
    int n;
    cin >> n;

    char a[100];
    char largest[100];

    int len = 0;
    int largestlen = 0;

    cin.get(); // to avoid \n as an i/p

    for (int i = 0; i < n; i++)
    {
        cin.getline(a, 100);

        // cout << a << endl;

        len = strlen(a);
        if (len > largestlen)
        {
            largestlen = len;
            strcpy(largest, a);
        }
    }

    cout << largest << "and" << largestlen << endl;
}