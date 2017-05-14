#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partitionArray(vector<int> &nums, int k);

int main()
{
	vector<int> t = { 9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9 };
	cout << partitionArray(t, 9) << endl;
	return 0;
}

int partitionArray(vector<int> &nums, int k)
{
	if (nums.size() == 0)
		return 0;
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
		if (k == nums.at(i))
			return i;
	if (k < nums.front())
		return 0;
	if (k > nums.back())
		return nums.size();
}