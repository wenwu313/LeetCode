#include<iostream>
#include<vector>
using namespace std;

int numTrees(int n) {
	vector<int> res;
	res.push_back(1);	
	for (int i = 1; i <= n; i++){
		int num = 0;
		for (int j = 1; j <= i; j++){
			num += res[j - 1] * res[i - j];
		}	
		res.push_back(num);
	}
	return res[n];
}

int main()
{
	cout << numTrees(3) << endl;
	cin.get();
	return 0;
}