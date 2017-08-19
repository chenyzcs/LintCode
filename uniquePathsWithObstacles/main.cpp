#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid)
{
	if (obstacleGrid.empty())
		return 0;
	size_t rows = obstacleGrid.size();
	size_t cols = obstacleGrid.front().size();
	vector<vector<int>> dp(rows, vector<int>(cols, 0));
	dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
	for (int i = 1; i < rows; i++)
	{
		if (obstacleGrid[i][0] == 1)
			dp[i][0] = 0;
		else
			dp[i][0] = dp[i - 1][0];
	}
	for (int j = 1; j < cols; j++)
	{
		if (obstacleGrid[0][j] == 1)
			dp[0][j] = 0;
		else
			dp[0][j] = dp[0][j - 1];
	}
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			if (obstacleGrid[i][j] == 1)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	return dp[rows - 1][cols - 1];
}

int main()
{
	vector<vector<int>> v = {
		{0,0},
		{0,0},
		{0,0},
		{1,0},
		{0,0}
	};
	cout << uniquePathsWithObstacles(v) << endl;
	return 0;
}