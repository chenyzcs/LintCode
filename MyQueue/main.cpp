#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
	stack<int> stack1;
	stack<int> stack2;

	MyQueue() {
		// do intialization if necessary
	}

	void push(int element) {
		// write your code here
		while (stack2.size())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.push(element);
		while (stack1.size())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}

	int pop() {
		// write your code here
		if (stack2.size())
		{
			int top_tmp = this->top();
			stack2.pop();
			return top_tmp;
		}
	}

	int top() {
		// write your code here
		if (stack2.size())
			return stack2.top();
	}
};

int main()
{
	MyQueue q;
	q.push(1);
	cout << q.pop() << endl;
	q.push(2);
	q.push(3);
	cout << q.top() << endl;
	cout << q.pop() << endl;
	return 0;
}