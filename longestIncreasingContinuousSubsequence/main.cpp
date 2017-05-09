#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int longestIncreasingContinuousSubsequence(vector<int>& A);

int main()
{
	int i = 0;
	vector<int> s = { 5,1,2,3,4 };
	cout << longestIncreasingContinuousSubsequence(s) << endl;
	cout << "Hello world!" << endl;
	return 0;
}

int longestIncreasingContinuousSubsequence(vector<int>& A)
{
	const int A_size = A.size();
	int max1 = 1;
	int len1 = 1;

	for (int i = 1; i < A_size; i++)
	{
		if (A[i] > A[i - 1])
		{
			len1++;
			max1 = (len1 > max1) ? len1 : max1;
		}
			
		else
		{
			len1 = 1;
		}
	}
	int max2 = 1;
	int len2 = 1;
	for (int i = 1; i<A_size; i++)
	{
		if (A[i] < A[i - 1])
		{
			len2++;
			max2 = (len2 > max2) ? len2 : max2;
		}
		else
		{
			len2 = 1;
		}
	}
	
	return (max1 > max2) ? max1 : max2;
}
