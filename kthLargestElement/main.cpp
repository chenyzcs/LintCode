#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthLargestElement(int k, vector<int> nums);

int main()
{
	vector<int> t = { 1,2,3,4,5 };
	kthLargestElement(1, t);
	return 0;
}

int kthLargestElement(int k, vector<int> nums)
{
	priority_queue<int, vector<int>, less<int>> pq;
	for (auto &i : nums)
		pq.push(i);
	int ret;
	for (int i = 0; i < k; i++)
	{
		ret = pq.top();
		pq.pop();
	}
	cout << ret << endl;
	return ret;
}