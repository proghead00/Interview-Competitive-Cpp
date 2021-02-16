#include <iostream>
#include <string>
using namespace std;

void sort(string a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {

            if (a[j] > a[j + 1])
            {
                string t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void substring(string s[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (s[i + 1].find(s[i]) != string::npos)
        {
            if (s[i + 2].find(s[i + 1]) != string::npos)
            {
                string t = s[i + 1];
                s[i + 1] = s[i + 2];
                s[i + 2] = t;
            }

            string t = s[i];
            s[i] = s[i + 1];
            s[i + 1] = t;
        }
    }
}
int main()
{
    int n;

    cin >> n;

    string s[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    sort(s, n);

    substring(s, n);

    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
}