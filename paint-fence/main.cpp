#include <iostream>

using namespace std;

int numWays(int n, int k)
{
	if (n == 1)
		return k;
	if (n == 2)
		return k*k;
	int f1 = k;
	int f2 = k*k;
	int val;
	for (int i = 2; i < n; i++)
	{
		val = (k - 1)*(f1 + f2);
		f1 = f2;
		f2 = val;
	}
	return val;
}

int main()
{
	cout << numWays(3, 2) << endl;
	return 0;
}