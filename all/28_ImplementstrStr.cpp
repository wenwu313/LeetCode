#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
	if (needle.empty())
		return 0;
	int m = haystack.size(), n = needle.size();
	for (int i = 0; i <= m - n; i++){
		int j;
		for (j = 0; j < n; j++){
			if (haystack[i + j] != needle[j])
				break;
		}
		if (j == needle.size())
			return i;
	}
	return -1;
}

int main()
{
	string s1 = "hgfabcdads";
	string s2 = "abc";
	cout << strStr(s1, s2) << endl;
	cin.get();
	return 0;
}

