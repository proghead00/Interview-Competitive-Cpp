#include <iostream>
#include <stack>>
using namespace std;

int main()
{
    string s;
    stack<char> st;

    cin >> s;

    int c = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (st.top() == '(')
                c++;

            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }

                st.pop(); // popping out the opening bracket
            }
        }
        else
        {
            st.push(s[i]);
        }
    }

    if (c == 0)
        cout << "No duplicate";

    else
        cout << "Duplicate";
}
