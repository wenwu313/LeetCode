//穷举所有子串 时间O(N^3)
bool isPalindrome(string &s, int begin, int end)
{
	while (begin < end){
		if (s[begin] == s[end]){
			++begin;
			--end;
		}
		else{
			return false;
			break;
		}			
	}
	return true;
}

string longestPalindrome(string s) {
	int maxLength = 0;
	string result(&s[0], &s[0] + 1);
	for (int i = 0; i < s.size(); ++i){
		for (int j = i + 1; j < s.size(); ++j){
			if (isPalindrome(s, i, j) && j - i + 1>maxLength){
				maxLength = j - i + 1;
				string temp(&s[i], &s[j] + 1);
				result = temp;
			}
		}		
	}
	return result;
}

//以一个或两个为中心  由中心向两边扫  O(N^2)
string  getSubString(string s, int left, int right)
{
	while (left >= 0 && right < s.size() && s[left] == s[right]){	
			left--;
			right++;
	}
	return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
	if (s.size() < 1) return s;
	string result = "";
	for (int i = 0; i < s.size(); i++){
		int left = i, right = i;
		string temp = getSubString(s, left, right);
		if (temp.size()>result.size())
			result = temp;
		right = i + 1;
		temp = getSubString(s, left, right);
		if (temp.size()>result.size())
			result = temp;
	}
	return result;
}

//Manacher 曼彻斯特 O(N)
string longestPalindrome(string s) {
	if (s.size() < 1) return s;
	int N = s.size();
	vector<int> p(2 * N + 1);
	p[0] = 1;
	int mx = 1, id = 0;
	for (int i = 1; i < N; ++i){
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i);
		else
			p[i] = 1;
		while ((i != p[i]) && (((i + p[i]) % 2 == 1)  //i != p[i]  到边
			|| (s[(i + p[i]) / 2 - 1] == s[(i - p[i]) / 2 - 1])))
			p[i]++;
		if (mx < i + p[i])
		{
			mx = i + p[i];
			id = i;
		}
	}

	int maxlen = 1;
	int index = 0;
	for (int i = 1; i < N; i++){
		if (p[i]>maxlen){
			maxlen = p[i];
			index = i;
		}
	}
	return s.substr((index - maxlen+1) / 2 , maxlen-1);
}