#include <iostream>
#include <vector>

using namespace std;

void sortIntegers2(vector<int>& A);
void quick_sort(vector<int>&arr, int low, int high);

int main()
{
	vector<int> t = { 19,-10,-2,40,3,36,57,25,66,51,5,40,-8,43,9,-5,0,4,55,28,63,67,-2,35,57,0,0,30,17,55,22,34,-4,42,57,52,4,65,6,-2,8,12,31,43,26,34,31,19,-3,36,34,11,58,23,13,7,17,10,33,-5,10,53,14,56,18,8,-6,-2,37,7 };
	sortIntegers2(t);
	for (auto &i : t)
		cout << i << " ";
	cout << endl;
	return 0;
}

void sortIntegers2(vector<int>& A)
{
	quick_sort(A, 0, A.size() - 1);
}

void quick_sort(vector<int>&arr, int low, int high)
{
	int pivot;
	if (low < high)
	{
		int pivotkey;
		pivotkey = arr[low];
		int i = low;
		int j = high;
		while (i < j)
		{
			while (i < j && arr[j] >= pivotkey)j--;
			swap(arr[i], arr[j]);
			while (i < j && arr[i] <= pivotkey)i++;
			swap(arr[i], arr[j]);
		}
		pivot = i;
		cout << pivot << endl;
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}
