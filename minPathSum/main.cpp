#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>> grid)
{
	if (grid.empty())
		return 0;
	size_t row = grid.size();
	size_t col = grid.front().size();
	vector<vector<int>> dp(row, vector<int>(col, 0));
	dp[0][0] = grid[0][0];
	for (int i = 1; i < col; i++)
		dp[0][i] = dp[0][i - 1] + grid[0][i];
	for (int i = 1; i < row; i++)
		dp[i][0] += dp[i - 1][0] + grid[i][0];
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			int min = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i][j - 1] : dp[i - 1][j];
			dp[i][j] = min + grid[i][j];
		}
	}
	return dp[row - 1][col - 1];
}

int main()
{
	vector<vector<int>> v = {
		{1,3,5,9},
		{8,1,3,4},
		{5,0,6,1},
		{8,8,4,0}
	};
	cout << minPathSum(v) << endl;
	return 0;
}