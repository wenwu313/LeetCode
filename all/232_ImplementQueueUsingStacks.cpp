#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class MyQueue {
private:
	stack<int> stack1;
	stack<int> stack2;

public:
	/** Initialize your data structure here. */
	MyQueue() {
		
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int result = peek();
		stack2.pop();
		return result;
	}

	/** Get the front element. */
	int peek() {
		if (stack2.empty()){
			while (!stack1.empty()){
				int temp = stack1.top();
				stack1.pop();
				stack2.push(temp);
			}
		}
		int result = stack2.top();
		return result;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (stack2.empty() && stack1.empty())  //return stack2.empty() && stack1.empty()
			return true;
		else
			return false;
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/


int main()
{   
	MyQueue obj = new MyQueue();  //ÎªÊ²Ã´³ö´í

	cin.get();
	return 0;
}

