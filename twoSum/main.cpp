#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

int main()
{
	vector<int> t = { 2,7,11,13 };
	return 0;
}

vector<int> twoSum(vector<int> &nums, int target)
{
	vector<int> _ans;
	for (int i = 0; i < nums.size(); i++)
	{
		int pat = target - nums[i];
		for (int j = 0; j < nums.size() && j != i; j++)
		{
			if (pat == nums[j])
			{
				if (i < j)
				{
					_ans.emplace_back(i + 1);
					_ans.emplace_back(j + 1);
				}
				else
				{
					_ans.emplace_back(j + 1);
					_ans.emplace_back(i + 1);
				}
			}
		}
	}
	return _ans;
}
