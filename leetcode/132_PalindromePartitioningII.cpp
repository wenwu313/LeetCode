#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//��ʱ  
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
	// isPal[i][j]��ʾ�ַ���s���Ӵ�s[i,j]�Ƿ�Ϊ���Ĵ�
	vector<vector<bool>> isPal(size, vector<bool>(size));
	// cut[j]��ʾ�Ӵ�s[0,j]����Ҫ����С�ָ���
	vector<int> cut(size);
	// cut[0,i]
	for (int i = 0; i < size; ++i){
		// [0,i]���ָ�i��
		cut[i] = i;
		// �ж�s[j,i]�Ƿ��ǻ��Ĵ�
		for (int j = 0; j <= i; ++j){
			// s[j,i]�ǻ��Ĵ�
			if (s[j] == s[i] && (i - j <= 1 || isPal[j + 1][i - 1])){
				isPal[j][i] = true;
				// s[0,i]�ǻ��Ĵ�
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

