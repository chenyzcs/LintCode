#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string largestNumber(vector<int> &num);
bool comp(const int &i1, const int &i2)
{
	return to_string(i1) + to_string(i2) > to_string(i2) + to_string(i1);
}

int main()
{
	vector<int> t = { 1, 20, 23, 4, 8 };
	cout << largestNumber(t) << endl;
	return 0;
}

string largestNumber(vector<int> &num)
{
	sort(num.begin(), num.end(), comp);
	if (!num.front())
		return "0";
	string _ret;
	for (auto &i : num)
		_ret += to_string(i);
	return _ret;
}