#include <iostream>
using namespace std;

int main(int argc, char)
{
    // 1. 0 and 1 are not a CB number.
    // 2. 2,3,5,7,11,13,17,19,23,29 are CB numbers.
    // 3. Any number not divisible by the numbers in point 2( Given above ) are also CB numbers.

    // Deepak's task -> no. of CB nos in the string
    //CB must not be sub or super string
    // Ex- In **4991**, both **499** and **991** are CB numbers but you can choose either **499** or **991**, not both.

    // - Further, the CB number formed can only be a sub-string of the string
    // Ex - In **481**, you can not take **41** as CB number because 41 is not a sub-string of **481**.

    string s;
    cin >> s;

    if (s.length() == 1)
    {
        char ch = s[0];
        if (ch == '1' || ch == '0')
        {
            cout << "Invalid";
            return;
        }

        int c = 1;

        int cb[100];
        for (int i = 0; i < s.length(); i++)
        {

            // int cb[] = {2,
            //             3,
            //             5,
            //             7,
            //             11,
            //             13,
            //             17,
            //             19,
            //             23,
            //             29};
            int cb2 = 2 * c - i;
            cb[i] = cb2; //2,3,5,7,..., 29
            c++;

            for (int j = 0; j < s.length(); j++)
            {
                if (j % cb[i] != 0)
                {
                    cb[i] = j;
                }
            }
        }
    }
}
