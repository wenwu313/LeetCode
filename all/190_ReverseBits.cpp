#include<iostream>
#include<vector>
#include <stdint.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
	uint32_t res = 0;
	for (int i = 0; i < 32; i++){
		res <<= 1;
		res |= (n & 1);		
		n >>= 1;
	}
	return res;
}

uint32_t reverseBits(uint32_t n) {
	unsigned int mask = 1 << 31, res = 0;
	for (int i = 0; i < 32; ++i) {
		if (n & 1) res |= mask;
		mask >>= 1;
		n >>= 1;
	}
	return res;
}


int main()
{
	cout << reverseBits(45) << endl;
	cin.get();
	return 0;
}

