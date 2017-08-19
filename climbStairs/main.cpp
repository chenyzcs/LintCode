#include <iostream>

using namespace std;

int climbStairs(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	int pre = 1;
	int end = 1;
	int val;
	for (int i = 1; i < n; i++)
	{
		val = pre + end;
		pre = end;
		end = val;
	}
	return val;
}

int main()
{
	cout << climbStairs(5) << endl;
	return 0;
}