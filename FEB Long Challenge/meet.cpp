#include <iostream>
using namespace std;

// L <= P <= R

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    int N;

    string P;
    string L, R;

    int hrL, minL;
    int hrR, minR;

    string output = "";

    int hrP, minP;

    while (T > 0)
    {
        getline(cin, P);

        // cin >> P; // scheduled time of chef

        hrP = (10 * (P[0] - '0')) + (P[1] - '0');

        minP = (10 * (P[3] - '0')) + (P[4] - '0');

        if (P[6] == 'P')
        {
            if (hrP < 12)
            {
                hrP += 12; //10PM -> 10+12 = 22
            }
        }

        if (P[6] == 'A')
        {
            if (hrP == 12)
            {
                hrP -= 12;
            }
        }

        cin >> N; // no. of friends' timings to be inputted
        cin.ignore();

        string Q;
        while (N > 0)
        {

            getline(cin, Q);
            for (int i = 0; i < Q.length(); i++)
            {
                if (i < 8)
                {
                    L.push_back(Q[i]);
                }
                if (i > 8)
                {
                    R.push_back(Q[i]);
                }
            }

            // getline(cin, L);

            // cout << L << endl;

            // getline(cin, R);
            // cout << R << endl;
            // cin >> L >> R;
            // getline(cin, L);

            // getline(cin, R);
            // L -> 12:45 PM
            // l2 -> 1245

            //   L:
            hrL = (10 * (L[0] - '0')) + (L[1] - '0');

            minL = (10 * (L[3] - '0')) + (L[4] - '0');

            if (L[6] == 'P')
            {
                if (hrL < 12)
                {
                    hrL += 12; //10PM -> 10+12 = 22
                }
            }

            if (L[6] == 'A')
            {
                if (hrL == 12)
                {
                    hrL -= 12;
                }
            }

            // R:
            hrR = (10 * (R[0] - '0')) + (R[1] - '0');

            minR = (10 * (R[3] - '0')) + (R[4] - '0'); // 10:59 PM -> 50+9

            if (R[6] == 'P')
            {
                if (hrR != 12)
                {
                    hrR += 12;
                }
            }

            if (R[6] == 'A')
            {
                if (hrR == 12)
                {
                    hrR -= 12;
                }
            }

            // L <= P <= R

            // if (hrL <= hrP)
            // {
            //     if (hrP <= hrR)
            //     {
            //         if (minL <= minP)
            //         {
            //             if (minP <= minR)
            //             {
            //                 // output += "1";
            //                 output.push_back('1');
            //             }
            //         }
            //     }
            // }
            // else
            //     // output += "0";
            //     output.push_back('0');

            L = "";
            R = "";

            if ((hrL > hrP) || (hrR < hrP))
                output.push_back('0');

            else if ((hrL == hrP && minL > minP) || (hrR == hrP && minR < minP))
                output.push_back('0');

            // else if (hrR == hrP && minR < minP)
            //     output.push_back('0');
            else
                output.push_back('1');
            N--;
        }

        T--;
        cout << output << endl;
        hrR = 0;
        hrP = 0;
        hrL = 0;
        minP = 0;
        minR = 0;
        minL = 0;
        output = "";
    }
}
