#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long int a, b, c, d, K;
        cin >> a >> b >> c >> d >> K;

        int st =  abs(c - a) + abs(d - b);
        if (st > K) cout << "NO" << "\n";
        else {


            if (st & 1) {
                if (K & 1)  cout << "YES" << "\n";
                else  cout << "NO" << "\n";
            }

            else {
                if (K % 2 == 0)
                    cout << "YES" <<  "\n";
                else cout << "NO" << "\n";
            }
        }
    }

}
