#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	//if (prices.size() < 2) return 0;   //去掉，leetcode报错！！
	int profit = 0;
	for (int i = 0; i < prices.size()-1; i++){
		if (prices[i + 1] - prices[i]>0) 
			profit += prices[i + 1] - prices[i];
	}
	return profit;
}

int maxProfit1(vector<int>& prices) {    //无措  i i-1
	int profit = 0;
	for (int i = 1; i < prices.size(); i++){
		if (prices[i] - prices[i - 1]>0)
			profit += prices[i] - prices[i - 1];
	}
	return profit;
}

//public int maxProfit(int[] prices) {   //Java程序这样没错，为什么！！！
//	int total = 0;
//	for (int i = 0; i< prices.length - 1; i++) {
//		if (prices[i + 1]>prices[i]) total += prices[i + 1] - prices[i];
//	}
//
//	return total;
//}

int main()
{
	vector<int> a1 = { };
	cout << maxProfit(a1) << endl;
	cin.get();
	return 0;
}