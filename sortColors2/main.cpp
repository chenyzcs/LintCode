#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortColors2(vector<int> &colors, int k);

int main()
{
	vector<int> t = { 3,2,3,3,4,3,3,2,4,4,1,2,1,1,1,3,4,3,4,2 };
	sortColors2(t, 4);
	return 0;
}

void sortColors2(vector<int> &colors, int k)
{
	if (colors.size() == 0)
		return;
	size_t col_size = colors.size();
	for (int i = 0; i < col_size; i++)
	{
		int min = i;
		for (int j = i + 1; j < col_size; j++)
		{
			if (colors[j] < colors[min])
				min = j;
		}
		if (colors[min] > k)
			break;
		std::swap(colors[i], colors[min]);
	}
}