#include <iostream>
#include <list>

using namespace std;

list<int> addLists(list<int> &l1, list<int> &l2);

int main()
{
	list<int> l1 = { 1,1,1,1,1 };
	list<int> l2 = { 9,8,8,8,8 };
	auto ret = addLists(l1, l2);
	for (auto &c : ret)
		cout << c << "-->";
	cout << endl;
	return 0;
}

list<int> addLists(list<int> &l1, list<int> &l2)
{
	list<int>::iterator l1_bg = l1.begin();
	list<int>::iterator l2_bg = l2.begin();
	list<int> ret;
	int tmp = 0;
	while (l1_bg != l1.end() && l2_bg != l2.end())
	{
		bool carry_flag = false;
		if (*l1_bg + *l2_bg + tmp >= 10)
		{
			tmp = (*l1_bg + *l2_bg + tmp) % 10;
			carry_flag = true;
		}
		else
		{
			tmp += *l1_bg + *l2_bg;
		}
		ret.push_back(tmp);
		tmp = (carry_flag) ? 1 : 0;
		l1_bg++;
		l2_bg++;
	}
	if (l1_bg == l1.end() && l2_bg == l2.end() && tmp)
		ret.push_back(tmp);
	while (l1_bg != l1.end())
	{
		ret.push_back(*l1_bg + tmp);
		l1_bg++;
	}
	while (l2_bg != l2.end())
	{
		ret.push_back(*l2_bg + tmp);
		l2_bg++;
	}
	return ret;
}