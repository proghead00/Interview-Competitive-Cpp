#include <iostream>
using namespace std;

void replace_dup(string &s, string &s2, int i) {
  if (i == s.size())
    return;

  if (s[i] == s[i+1]) {
    s2.push_back(s[i]);
    s2.push_back('*');
  } else {
    s2.push_back(s[i]);
  }
  replace_dup(s, s2, i+1);
}


int main() {
  string s = "hello";
  int n = s.size();

  string s2;
  replace_dup(s, s2, 0);
  cout << s2 << "\n";
}