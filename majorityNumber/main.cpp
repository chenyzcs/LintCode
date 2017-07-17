#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int majorityNumber(vector<int> nums) {
	if (nums.empty())
		return -1;
	std::sort(nums.begin(), nums.end());
	size_t sz = nums.size();
	for (int i = 0; i < sz / 2; i++) {
		if (nums[i] == nums[i + sz / 2])
			return nums[i];
	}
}

int main()
{
	vector<int> v = { 1,1,1,1,2,2,2 };
	cout << majorityNumber(v) << endl;
	return 0;
}