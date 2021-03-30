#include <iostream>
using namespace std;

void remove_dup(string s, int i)
{
    if(i==s.size())
        return;

    if(s[i]==s[i+1])
    {
        remove_dup(s, i+1);
    }

  else{
    cout << s[i];
    remove_dup(s, i+1); }

}



int main() {
  string s = "maaaaam";
  int n = s.size();

  string s2;
  remove_dup(s, 0);
//   cout << s  << "\n";
}
