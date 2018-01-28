#include<iostream>
using namespace std;

int climbStairs(int n) {
	int num1 = 1, num2 = 2;
	if (n < 1) return -1;
	if (n == 1) return num1;
	if (n == 2) return num2;
	int count;
	for (int i = 2; i < n; ++i){
		count = num2 + num1;
		num1 = num2;
		num2 = count;
	}
	return count;
}

int main()
{
	int n = 1;
	cout << climbStairs(n)<<endl;
	cin.get();
	return 0;
}