#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

void Combinations(string digits, vector<string> map, string temp, vector<string> &result,int begin)
{
	if (begin >= digits.size()){
		result.push_back(temp);
		return;
	}
	string table = map[digits[begin] - '0'];
	for (int i = 0; i < table.size(); i++){
		temp.append(1, table[i]);
		Combinations(digits, map, temp, result, begin + 1);
		temp = temp.substr(0, temp.size() - 1);
	}	
}


vector<string> letterCombinations(string digits) {
	vector<string> result;
	if (digits.empty())
		return result;
	vector<string> map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	string temp = "";
	Combinations(digits, map, temp, result, 0);
	return result;
}

int main()
{
	vector<string> ans = letterCombinations("23");
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
	cin.get();
	return 0;
}

