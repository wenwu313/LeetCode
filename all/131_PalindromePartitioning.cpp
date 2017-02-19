#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(const string &s, int begin, int end){
	while (begin < end){
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}

void partition(string s, vector<vector<string>> &result, vector<string> &temp,int begin,int len) {
	if (begin >= len){
		result.push_back(temp);
		return;
	}		
	for (int i = begin; i < len; i++){
		if (!isPalindrome(s, begin, i))
			continue;
		temp.push_back(s.substr(begin, i - begin + 1));
		partition(s, result, temp, i + 1, len);
		temp.pop_back();
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> result;
	vector<string> temp;
	partition(s, result, temp, 0, s.size());
	return result;
}

int main()
{
	string s = "aab";
	vector<vector<string>> ans = partition(s);
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	cin.get();
	return 0;
}

