#include <iostream>
using namespace std;

int main()
{

    int t;

    int m, h;

    int bmi;
    int category;

    cin >> t;
    while (t--)
    {
        cin >> m >> h;

        bmi = m / (h * h);

        if (bmi <= 18)
        {
            category = 1;
        }

        else if (bmi >= 19 and bmi <= 24)
            category = 2;

        else if (bmi >= 25 && bmi <= 29)
            category = 3;

        else
            category = 4;

        cout << category << endl;
    }
}