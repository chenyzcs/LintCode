#include <iostream>
#include <vector>

using namespace std;

int median(vector<int> &nums);
void quick_sort(vector<int> &arr, int low, int high);

int main()
{
	vector<int> t = { 4, 5, 1, 2, 3 };
	cout << median(t) << endl;
	return 0;
}

int median(vector<int> &nums)
{
	quick_sort(nums, 0, nums.size() - 1);
	return (nums.size() % 2 == 0) ? nums[nums.size() / 2 - 1] : nums[nums.size() / 2];
}

void quick_sort(vector<int> &arr, int low, int high)
{
	int pivot;
	if (low < high)
	{
		int pivotkey = arr[low];
		int i = low;
		int j = high;
		while (i < j)
		{
			while (i < j && arr[j] >= pivotkey)
				j--;
			std::swap(arr[i], arr[j]);
			while (i < j && arr[i] <= pivotkey)
				i++;
			std::swap(arr[i], arr[j]);
		}
		pivot = i;
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}
