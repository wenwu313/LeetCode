#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//超时  
bool isPalindrome(const string &s, int begin, int end){
	while (begin < end){
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}

void minCut(string s, int &minc,int begin,int len,int temp) { //aaabaa
	if (begin >= len){
		if (temp < minc)
			minc = temp;
		return;
	}		
	for (int i = begin; i < len; i++){	
		if (!isPalindrome(s, begin, i))
			continue;
		if (i != len-1)
			temp += 1;
		minCut(s, minc, i + 1, len, temp);
		if (i != len - 1)
			temp -= 1;
	}
}

int minCut(string s) {
	int size = s.size();
	if (size == 0){
		return 0;
	}
	// isPal[i][j]表示字符串s的子串s[i,j]是否为回文串
	vector<vector<bool>> isPal(size, vector<bool>(size));
	// cut[j]表示子串s[0,j]所需要的最小分割数
	vector<int> cut(size);
	// cut[0,i]
	for (int i = 0; i < size; ++i){
		// [0,i]最多分割i次
		cut[i] = i;
		// 判断s[j,i]是否是回文串
		for (int j = 0; j <= i; ++j){
			// s[j,i]是回文串
			if (s[j] == s[i] && (i - j <= 1 || isPal[j + 1][i - 1])){
				isPal[j][i] = true;
				// s[0,i]是回文串
				if (j == 0){
					cut[i] = 0;
				}//if
				else{
					cut[i] = min(cut[i], cut[j - 1] + 1);
				}//else
			}//if
		}//for
	}//for
	return cut[size - 1];
}

int minCut(string s) {
	int minc = s.size() - 1;
	minCut(s, minc, 0, s.size(), 0);
	return minc;
}

int main()
{
	string s = "aaabaa";
	cout << minCut(s) << endl;
	cin.get();
	return 0;
}

