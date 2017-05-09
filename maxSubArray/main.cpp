#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> nums);

int main()
{
	vector<int> s1 = { -2,2,-3,4,-1,2,1,-5,3 };
	maxSubArray(s1);
	return 0;
}

int maxSubArray(vector<int> nums)
{
	int bg = 0;
	int ed = 0;
	int max = nums[0];
	int sum = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		sum += nums[i];
		if (sum > max)
			max = sum;
		if (sum < max)
		{
			sum = nums[i];
		}
	}
	return max;
}