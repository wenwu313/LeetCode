#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
	if (s.empty() && t.empty())
		return true;
	if (s.size() != t.size()) return false;
	unordered_map<char, int> map;
	for (int i = 0; i < s.size(); i++){
		map[s[i]]++;
		map[t[i]]--;
	}
	for (auto count : map){
		if (count.second) return false;
	}
	return true;
}


int main()
{


	cout << s << endl;
	cin.get();
	return 0;
}

