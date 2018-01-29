#include<iostream>
#include<string>
using namespace std;

string reverseString(string s) {
	int left = 0, right = s.size() - 1;
	while (left < right){
		swap(s[left], s[right]);
		left++;
		right--;
	}
	return s;
}

string reverseString(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j){
		swap(s[i++], s[j--]);
	}

	return s;
}

int main()
{
	cout << reverseString("hello") << endl;
	cin.get();
	return 0;
}

