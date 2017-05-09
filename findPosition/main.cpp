#include <iostream>
#include <vector>

using namespace std;

int findPosition(vector<int> &A, int target)
{
	int start = 0;
	int end = A.size() - 1;
	while (start <= end)
	{
		auto mid = (start + end) / 2;
		if (A[mid] < target)
		{
			start = mid + 1;
		}
		else if (A[mid] > target)
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	vector<int> t_v = {};
	cout << t_v.size() << endl;
	auto p = findPosition(t_v, -1);
	cout << p << endl;
	return 0;
}