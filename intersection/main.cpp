#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

int main()
{
	vector<int> t1, t2;
	t1 = { 1,2,2,1 };
	t2 = { 2,2 };
	intersection(t1, t2);
	return 0;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> ret;
	vector<int> ans;
	if (nums1.size() == 0 || nums2.size() == 0)
		return ans;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int i, j;
	i = 0; j = 0;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])i++;
		else if (nums1[i] > nums2[j])j++;
		else
		{
			if (ans.empty() || ans.back() != nums1[i])
				ans.emplace_back(nums1[i]);
			i++; j++;
		}
	}
			
	return ans;
}