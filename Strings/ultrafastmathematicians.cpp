#include <iostream>
using namespace std;

int main(int argc, char)
{
    // no made of 0 , 1
    // i-th digit = 1 if i-th digit of 2 diff nos. differ
    //else i-th digit = 0

    // 0010 0010
    // ans: 0000

    string s1, s2;

    string s3;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] - s2[i] == 0)
        {
            s3[i] = '0';
            cout << s3[i];
        }
        else
        {
            s3[i] = '1';
            cout << s3[i];
        }
    }
}