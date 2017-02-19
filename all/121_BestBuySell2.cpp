#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() < 2) return 0;
	vector<int> diff(prices.size() - 1);
	for (int i = 0; i < prices.size() - 1; i++){
		diff[i] = prices[i + 1] - prices[i];
	}
	int profit = 0, maxprofit = 0;
	for (int i = 0; i < diff.size(); i++){
		if (profit>0) profit += diff[i];
		else profit = diff[i];
		if (profit>maxprofit)
			maxprofit = profit;
	}
	return maxprofit;

}

int maxProfit1(vector<int>& prices) {
	int maxCur = 0, maxSoFar = 0;
	for (int i = 1; i < prices.size(); i++) {
		maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
		maxSoFar = max(maxCur, maxSoFar);
	}
	return maxSoFar;
}

int main()
{
	vector<int> a1 = { 1,3,4,2,6,8,2};
	cout << maxProfit1(a1) << endl;
	cin.get();
	return 0;
}