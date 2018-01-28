#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
	if (s.empty())
		return true;
	int l = 0, r = s.size() - 1;
	for (int i = 0; i < s.size(); i++){
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
	}
	while (l < r){
		while (l < r && !((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9'))){
			l++;
		}
		while (l < r && !(s[r] >= 'a' && s[r] <= 'z' || (s[r] >= '0' && s[r] <= '9'))){
			r--;
		}
		if (s[l] != s[r])
			return false;
		else{
			l++;
			r--;
		}
	}
	return true;
}

int main()
{
	//cout << isPalindrome("race a car") << endl;
	cout << toupper('a') << endl;
	cin.get();
	return 0;
}

