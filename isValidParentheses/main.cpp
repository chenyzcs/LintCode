#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidParentheses(string& s);

int main()
{
	string s = "()";
	cout << char(124);
	cout << isValidParentheses(s) << endl;
	return 0;
}

bool isValidParentheses(string& s)
{
	vector<char> char_stack;
	char_stack.push_back(s[0]);
	if (s.size() <= 1)
		return false;
	for (int i = 1; i < s.size(); i++)
	{
		if (char_stack.size() == 0)
		{
			char_stack.push_back(s[i]);
			continue;
		}
		if (int(s[i]) - int(char_stack.back()) < 3 
			&& int(s[i]) - int(char_stack.back()) > 0)
			//&& int(s[i]) != int(char_stack.back()))
		{
			char_stack.pop_back();
		}
		else
		{
			char_stack.push_back(s[i]);
		}
		
	}
	
	return char_stack.size() == 0;
}