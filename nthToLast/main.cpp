#include <iostream>
#include <list>

using namespace std;

list<int> nthToLast(list<int> &head, int n);

int main()
{
	list<int> l = { 3,2,1,5 };
	auto ans = nthToLast(l, 2);
	for (auto &c : ans)
		cout << c << " ";
	cout << endl;
	return 0;
}

list<int> nthToLast(list<int>& head, int n)
{
	auto bg = head.begin();
	int len = 0;
	while (bg != head.end())
	{
		bg++;
		len++;
	}
	int tag = len - n;
	bg = head.begin();
	while (tag)
	{
		bg++;
		tag--;
	}
	list<int> ret;
	while (bg != head.end())
		ret.push_back(*bg++);
	return ret;
}
