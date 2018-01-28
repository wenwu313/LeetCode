#include<iostream>
#include<string>
using namespace std;

string addBinary(string a, string b) {
	if (a == "")  return b;
	if (b == "")  return a;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string result = "";
	int m = a.size(), n = b.size();
	int maxlen = m;
	if (m < n){
		a.append(n - m, '0');
		maxlen = n;
	}
	else
		b.append(m - n, '0');
	int carry = 0;
	
	for (int i = 0; i < maxlen; i++){
		int temp = (a[i] - '0') + (b[i] - '0') + carry;
		result.append(1, temp % 2 + '0');
		carry = temp / 2;
	}
	if (carry)
		result.append(1, carry + '0');
	reverse(result.begin(), result.end());
	return result;
}

string addBinary(string a, string b)
{
	string s = "";

	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || c == 1)
	{
		c += i >= 0 ? a[i--] - '0' : 0;
		c += j >= 0 ? b[j--] - '0' : 0;
		s = char(c % 2 + '0') + s;
		c /= 2;
	}
	return s;
}

int main()
{
	cout << addBinary("111", "110") << endl;
	cin.get();
	return 0;
}

