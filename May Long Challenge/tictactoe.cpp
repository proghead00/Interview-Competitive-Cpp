
#include <algorithm>
#include <iostream>

using namespace std;

string s[3];

int cntX, cntO, cntRem;

void cntXO()
{
    cntX = cntO = 0;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
        {
            if (s[i][j] == 'X')
                cntX++;
            if (s[i][j] == 'O')
                cntO++;
        }
    cntRem = 9 - cntX - cntO;
}
bool winner(char ip)
{
    // left and right diagonals check
    if (s[0][0] == ip && s[0][0] == s[1][1] && s[1][1] == s[2][2])
        return 1;
    if (s[0][2] == ip && s[0][2] == s[1][1] && s[1][1] == s[2][0])
        return 1;

    // rows and cols check
    for (size_t i = 0; i < 3; i++)
    {
        if (s[i][0] == ip && s[i][0] == s[i][1] && s[i][1] == s[i][2])
            return 1;
        if (s[0][i] == ip && s[0][i] == s[1][i] && s[1][i] == s[2][i])
            return 1;
    }
    return 0;
}

int obsCheck()
{
    if (cntX < cntO)
        return 3;
    if (cntX > cntO + 1)
        return 3;

    bool x_win = winner('X');
    bool o_win = winner('O');

    if (x_win && o_win) // not possible to have 2 winners at once
        return 3;
    if (x_win && cntX == cntO) // observation
        return 3;
    if (o_win && cntX > cntO) // observation
        return 3;
    if (x_win || o_win)
        return 1;
    if (cntRem == 0)
        return 1;
    return 2;
}
void solve()
{
    for (int i = 0; i < 3; i++)
        cin >> s[i];
    cntXO();
    cout << obsCheck() << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
