#include <iostream>
#include <vector>

using namespace std;

void wiggleSort(vector<int>& nums);
void wiggleSort2(vector<int>& nums);

void quick_sort(vector<int> &arr, int low, int high);

int main()
{
	vector<int> t = { 1,2,3,4,5,6,7 };
	wiggleSort(t);
	for (auto &i : t)
		cout << i << " ";
	cout << endl;
	return 0;
}

void wiggleSort(vector<int>& nums)
{
	quick_sort(nums, 0, nums.size() - 1);
	int first, last;
	first = 1;
	last = nums.size() - 1;
	for (; first < nums.size(); first += 2)
	{
		int max_tmp = nums[last];
		for (int i = last; i > first; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[first] = max_tmp;
		for (auto &i : nums)
			cout << i << " ";
		cout << endl;
	}
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

void wiggleSort2(vector<int>& nums)
{

}