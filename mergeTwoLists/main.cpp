#include <iostream>
#include <list>

using namespace std;

list<int> mergeTwoLists(list<int>& l1, list<int>& l2);

int main()
{
	list<int> l1 = { };
	list<int> l2 = { 0,3,3 };
	auto ans = mergeTwoLists(l1, l2);
	return 0;
}

list<int> mergeTwoLists(list<int>& l1, list<int>& l2)
{
	auto bg1 = l1.begin();
	auto bg2 = l2.begin();
	list<int> ret;
	while (bg1 != l1.end() && bg2 != l2.end())
	{
		if (*bg1 > *bg2)
			ret.push_back(*bg2++);
		else
			ret.push_back(*bg1++);
	}
	if (bg1 != l1.end()) {
		for (; bg1 != l1.end(); bg1++)
			ret.push_back(*bg1);
	}
	if (bg2 != l2.end()) {
		for (; bg2 != l2.end(); bg2++)
			ret.push_back(*bg2);
	}
	for (auto &c : ret)
		cout << c << "-->";
	cout << endl;
	return ret;
}
