#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &nums);

int main()
{
	vector<int> t = { -2,-3,5,-1,-4,5,-11,7,1,2,3,4,-7,-1,-2,-3,-4,-5 };
	threeSum(t);
	return 0;
}

static bool comp(vector<int> &n1, vector<int> &n2)
{
	if (n1[0] == n2[0])
	{
		if (n1[1] == n2[1])
		{
			return n1[2] < n2[2];
		}
		else return n1[1] < n2[1];
	}
	else return n1[0] < n2[0];
}

vector<vector<int> > threeSum(vector<int> &nums)
{
	if (nums.size() == 0)
		return{};
	std::sort(nums.begin(), nums.end());
	vector<int> tmp;
	tmp.push_back(nums[0]);

	
	vector <vector<int>> _ret;
	for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
	{
		/*if (nums[i] == nums[i + 1])
			i++;*/
		for (int j = nums.size() - 1; j > 0 && nums[j] >= 0; j--)
		{
			int pat = 0 - nums[i] - nums[j];
			for (int k = i + 1; k < j; k++)
			{
				if (pat == nums[k])
					_ret.push_back({ nums[i],pat,nums[j] });
			}
		}
	}
	vector<vector<int>> _ans;
	if (_ret.size() == 0)
		return{};
	_ans.push_back(_ret[0]);
	//for (auto &i : _ans)
	//{
	//	for (auto &i1 : i)
	//		cout << i1 << " ";
	//	cout << endl;
	//}
	std::sort(_ret.begin(), _ret.end(), comp);
	//cout << endl;
	/*for (auto &i : _ans)
	{
		for (auto &i1 : i)
			cout << i1 << " ";
		cout << endl;
	}*/
	for (int i = 1; i < _ret.size(); i++)
	{
		if (_ret[i][0] == _ans.back()[0] &&
			_ret[i][1] == _ans.back()[1])
			continue;
		_ans.push_back(_ret[i]);
	}
	for (auto &i : _ans)
	{
		for (auto &i1 : i)
			cout << i1 << " ";
		cout << endl;
	}
		
	return _ans;
}