class Solution {
public:
	bool isValid(string ip){
		int value = stoi(ip);
		if (ip[0] == '0'){
			return (ip.size() == 1);
		}
		else{
			if (value <= 255)
				return true;
			else
				return false;
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		int n = s.size();
		if (n > 12)
			return result;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				for (int k = j + 1; k < n - 1; k++){
					string ip1 = s.substr(0, i + 1);
					string ip2 = s.substr(i + 1, j - i);
					string ip3 = s.substr(j + 1, k - j);
					string ip4 = s.substr(k + 1, n - k - 1);
					if (isValid(ip1) && isValid(ip2) && isValid(ip3) && isValid(ip4)){
						string ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
						result.push_back(ip);
					}
				}
			}
		}
		return result;
	}
};