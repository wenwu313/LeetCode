#include<iostream>
using namespace std;

int titleToNumber(string s) {	 
	int num = 0;
	for (int i = 0; i < s.size(); i++){
		num = num * 26 + s[i] - 'A' + 1;
	}
	return num;
}

int titleToNumber1(string s) {
	int col = 0;
	for (int i = s.length(); i > 0; i--) {
		col += (s[i - 1] - 'A' + 1) * pow(26, (s.length() - i));
	}
	return col;
}

int main()
{
	string s = "AB";
	cout << titleToNumber(s) << endl;
	cin.get();
	return 0;
}