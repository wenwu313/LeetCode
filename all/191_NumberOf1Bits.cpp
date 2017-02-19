#include<iostream>
#include<vector>
#include <stdint.h>
using namespace std;

int hammingWeight(uint32_t n) {
	int count = 0;
	while (n){
		if (n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}

int hammingWeight(uint32_t n) {
	int count = 0;
	uint32_t a = 1;
	while (a){
		if (n & a)
			count++;
		a <<= 1;
	}
	return count;
}

int hammingWeight(uint32_t n) {
	int count = 0;
	while (n){
		n = n&(n - 1);
		count++;
	}
	return count;
}

int main()
{
	cout << hammingWeight(67) << endl;
	cin.get();
	return 0;
}

