#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
	std::vector<int> min_stack;
	int min_i;
	MinStack() {
		// do initialization if necessary
		this->min_i = 0xffff;
		min_stack.clear();
	}

	void push(int number) {
		// write your code here
		min_stack.push_back(number);
	}

	int pop() {
		// write your code here
		if (min_stack.back() == this->min_i)
			this->min_i = 0xffff;
		int tmp = min_stack.back();
		min_stack.pop_back();
		return tmp;
	}

	int min() {
		// write your code here
		for (auto &c : min_stack)
			if (c < this->min_i)
				this->min_i = c;
		return this->min_i;
	}
};

int main()
{
	return 0;
}