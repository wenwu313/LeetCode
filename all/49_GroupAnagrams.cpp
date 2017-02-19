#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> result;
	if (strs.empty())
		return result;
	unordered_map<string, vector<string>> map;
	map.clear();
	for (string str : strs){
		string sortstr(str);
		sort(sortstr.begin(), sortstr.end());
		map[sortstr].push_back(str);
	}
	for (auto temp : map){
		result.push_back(temp.second);
	}
	return result;
}

int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> solution = groupAnagrams(strs);
	for (int i = 0; i < solution.size(); i++){
		vector<string> temp = solution[i];
		for (int j = 0; j < temp.size(); j++){
			cout << solution[i][j] << ' ';
		}
		cout << endl;
	}
	cin.get();
	return 0;
}


