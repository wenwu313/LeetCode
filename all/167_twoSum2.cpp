#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
	int begin = 0, end = numbers.size() - 1;
	vector<int> index(2);
	while (begin < end){
		int sum = numbers[begin] + numbers[end];
		if (sum < target) begin++;
		else if (sum > target) end--;
		else{
			index[0] = begin + 1;
			index[1] = end + 1;
			break;
		}
	}
	return index;
}

//return vector<int>({lo+1,hi+1});

int main()
{
	vector<int> a1 = { 2, 7, 11, 15 };
	vector<int> ans = twoSum(a1, 9);
	cout << ans[0]<<' '<<ans[1]<<endl;
	cin.get();
	return 0;
}