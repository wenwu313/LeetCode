bool isPowerOfTwo(int n) {
	if (n <= 0) return false;
	return !(n&(n - 1));
}

bool isPowerOfTwo(int n) {
    return n > 0 && !(n&(n-1));
}

bool isPowerOfTwo(int n) {
	if (n<1)
		return false;
	int count = 0;
	while (n){
		n = n & (n - 1);
		count++;
	}
	if (count == 1)
		return true;
	return false;
}