#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void sortLetters(string &letters);

int main()
{
	string t = "abAcD";
	sortLetters(t);
	cout << t << endl;
	return 0;
}

void sortLetters(string &letters)
{
	if (letters.empty())
		return;
	string lo_letter, hi_letter;
	for (auto &c : letters)
	{
		if (c >= 'a' && c <= 'z')
			lo_letter += c;
		else
			hi_letter += c;
	}
	//sort(lo_letter.begin(), lo_letter.end());
	//sort(hi_letter.begin(), hi_letter.end());
	letters.clear();
	letters = lo_letter + hi_letter;
}