#include <bits/stdc++.h>
using namespace std;

void sol()
{
   ll t;
   cin >> t;
   int ans = 0;
   while (t--)
   {
      ll n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      vector<ll> v(k);
      for (ll i = 0; i < k; i++)
      {
         cin >> v[i];
         v[i]--;
      }
      for (ll i = 0; i < n - 1; i++)
      {
         if (s[i] == s[i + 1])
            ans += 2;
         else
            ans++;
      }

      for (ll i = 0; i < k; i++)
      {

         if (s[v[i]] == '1')
            s[v[i]] = '0';
         else
            s[v[i]] = '1';

         int in = v[i];
         if (v[i] > 0)
         {
            if (s[in] == s[in - 1])
               ans++;
            else
               ans--;
         }
         if (v[i] < n - 1)
         {
            if (s[in] == s[in + 1])
               ans++;
            else
               ans--;
         }
         cout << ans << "\n";
      }
   }
}
int main()
{  ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   sol();
   return 0;
}