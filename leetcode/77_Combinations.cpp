class Solution {
public:
	void combine(int n, int k, int begin, vector<vector<int>> &result, vector<int> &temp)
	{
		if (k == 0){
			result.push_back(temp);
			return;
		}
		for (int i = begin; i <= n; ++i){
			temp.push_back(i);
			combine(n, k - 1, i + 1, result, temp);
			temp.pop_back();
		}

	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> temp;
		combine(n, k, 1, result, temp);
		return result;
	}
};