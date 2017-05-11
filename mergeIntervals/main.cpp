#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

vector<Interval> merge(vector<Interval> &intervals);
bool comp(const Interval &i1, const Interval &i2)
{
	return i1.start < i2.start;
}
bool operator<(const Interval &i1, const Interval &i2)
{
	return i1.start < i2.start;
}

int main()
{
	vector<Interval> t;
	Interval t1(1, 3);
	Interval t2(2, 6);
	Interval t3(8, 10);
	Interval t4(15, 18);
	t.push_back(t1);
	t.push_back(t3);
	t.push_back(t2);
	t.push_back(t4);

	auto ans = merge(t);
	return 0;
}



vector<Interval> merge(vector<Interval> &intervals)
{
	if (intervals.empty())
		return{};
	std::sort(intervals.begin(), intervals.end(), comp);
	vector<Interval> _ret;
	_ret.emplace_back(intervals[0]);
	for (int i = 1; i < intervals.size(); i++)
	{
		if (_ret.back().end >= intervals[i].start)
			_ret.back().end = (_ret.back().end > intervals[i].end) ? _ret.back().end : intervals[i].end;
		else
			_ret.emplace_back(intervals[i]);
	}
	return _ret;
}
