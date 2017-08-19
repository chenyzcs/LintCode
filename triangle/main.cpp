#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>> triangle)
{
	if (triangle.empty())
		return 0;
	int rows = triangle.size();
	int cols = triangle.front().size();
	vector<vector<int>> dp(rows);
	dp[0].push_back(triangle[0][0]);
	for (int i = 1; i < rows; i++)
		for (int j = 0; j <= i; j++)
			dp[i].emplace_back(0);
	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < dp[i - 1].size() + 1; j++)
		{
			int min;
			if (j - 1 < 0)
				min = dp[i - 1][j];
			else if (j + 1 > dp[i - 1].size())
				min = dp[i - 1][j - 1];
			else
			{
				min = (dp[i - 1][j] > dp[i - 1][j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
			}
			dp[i][j] = min + triangle[i][j];
		}
	}

	int min = 0xffff;
	for (int i = 0; i < dp[rows - 1].size(); i++)
		if (dp[rows - 1][i] < min)
			min = dp[rows - 1][i];
	return min;
}

int main()
{
	vector<vector<int>> v = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	cout << minimumTotal(v) << endl;
	return 0;
}