#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

int main()
{
	vector<int> t1, t2;
	t1 = { 1,2,2,1 };
	t2 = { 2,2 };
	auto ans = intersection(t1, t2);
	return 0;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int i = 0, j = 0;
	vector<int> _ret;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
			i++;
		else if (nums1[i] > nums2[j])
			j++;
		else
		{
			_ret.push_back(nums1[i]);
			i++; j++;
		}
	}
	return _ret;
}