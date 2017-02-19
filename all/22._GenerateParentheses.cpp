#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> generateParenthesis(int n) {
	vector<string> res;
	addingpar(res, "", n, 0);
	return res;
}
void addingpar(vector<string> &v, string str, int n, int m){
	if (n == 0 && m == 0) {
		v.push_back(str);
		return;
	}
	if (m > 0){ addingpar(v, str + ")", n, m - 1); }
	if (n > 0){ addingpar(v, str + "(", n - 1, m + 1); }
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	addingpar(res, "", n, n);
	return res;
}
void addingpar(vector<string> &res, string str, int left, int right){
	if (0 == left && 0 == right)
	{
		res.push_back(str);
		return;
	}
	if (left > 0)
		addingpar(res, str + '(', left - 1, right);

	if (left < right)
		addingpar(res, str + ')', left, right - 1);
}

vector<string> generateParenthesis(int n) {

}

int main()
{
	vector<string> str = generateParenthesis(3);
	for (int i = 0; i < str.size(); i++){
		cout << str[i] << endl;
	}
	cin.get();
	return 0;
}

