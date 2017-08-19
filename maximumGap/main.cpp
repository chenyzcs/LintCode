#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumGap(vector<int> nums);

int main()
{
	vector<int> t{ 1, 9, 2, 5 };
	cout << maximumGap(t) << endl;
	return 0;
}

int maximumGap(vector<int> nums)
{
	if (nums.empty() || nums.size() < 2)
		return 0;
	sort(nums.begin(), nums.end());
	int max_gap = nums[1] - nums[0];
	for (int i = 2; i < nums.size(); i++)
	{
		if (max_gap < nums[i] - nums[i - 1])
			max_gap = nums[i] - nums[i - 1];
	}
	return max_gap;
}