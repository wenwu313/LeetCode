class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> ugly(n, INT_MAX);
		ugly[0] = 1;
		vector<int> index(primes.size(), 0);
		for (int i = 1; i < n; i++){
			for (int j = 0; j < primes.size(); j++){
				if (ugly[index[j]] * primes[j] < ugly[i]){
					ugly[i] = ugly[index[j]] * primes[j];
				}
			}
			for (int j = 0; j < primes.size(); j++){
				index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
			}
		}
		return ugly[n - 1];
	}
};