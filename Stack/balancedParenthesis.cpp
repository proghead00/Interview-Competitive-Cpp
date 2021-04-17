#include <iostream>
#include <stack>
using namespace std;

bool isvalid(char *s)
{
	stack<char> st;

	for (int i = 0; s[i] != '\0'; i++)
	{
		char ch = s[i];

		if (ch == '(')
		{
			st.push(ch);
		}

		else if (s[i] == ')')

		{
			if (st.empty() == true or st.top() == ')')
				return false;

			st.pop();
		}
	}
	return st.empty();
}

int main()
{

	char s[100000] = "a+b+ ()(b)";

	if (isvalid(s))
	{
		cout << "Yes";
	}
	else
		cout << "No";

	cout << endl;
	// cout << isvalid(s) << endl;
}