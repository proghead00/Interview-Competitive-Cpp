#include <iostream>
using namespace std;

void pi(string s, int i, string &s2)
{
    if(i==s.size())
        return;

    if(s[i]=='p' and s[i+1]=='i')
    {
        s2.push_back('3');
        s2.push_back('.');
        s2.push_back('1');
        s2.push_back('4');

        pi(s, i+2, s2);

    }
    else
        {   
            s2.push_back(s[i]);
            pi(s, i+1, s2);
        } 

    
}

int main() {
   
   string s2;
   
   pi("xabpixx3.15x", 0, s2);

    cout << s2;

   
 }
