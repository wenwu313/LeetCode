#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s) {
	stack<char> stack;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '{' || s[i] == '(' || s[i] == '['){
			stack.push(s[i]);
		}
		if (s[i] == '}' || s[i] == ')' || s[i] == ']'){
			if (stack.empty()) return false;
			char temp = stack.top();
			stack.pop();
			if (temp == '{' && s[i] != '}' ||
				temp == '(' && s[i] != ')' ||
				temp == '[' && s[i] != ']')
				return false;
		}
	}
	return stack.empty();
}

bool isValid(string s) {
	stack<char> stack;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '(')
			stack.push(')');
		else if (s[i] == '{')
			stack.push('}');
		else if (s[i] == '[')
			stack.push(']');
		else if (stack.empty() || stack.top() != s[i])
			return false;
		else stack.pop();
	}
	return stack.empty();
}


int main()
{
	cout<<isValid("([])")<<endl;
	cin.get();
	return 0;
}

