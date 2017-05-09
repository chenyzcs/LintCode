#include <iostream>
#include <vector>

using namespace std;

void sortIntegers(vector<int> &A) {
	int temp;
	for (int i = 0; i < A.size() - 1; ++i) {
		for (int j = i; j < A.size() - 1; ++j) {
			if (A[i] >= A[j + 1]) {
				temp = A[i];
				A[i] = A[j + 1];
				A[j + 1] = temp;
			}
		}

	}
}

int main() {
	std::cout << "Hello, World!" << std::endl;
	vector<int> a = { 3, 2, 1, 4, 5 };
	sortIntegers(a);
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}
	return 0;
}