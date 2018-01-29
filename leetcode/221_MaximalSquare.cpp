class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		int rows = matrix.size(), cols = matrix[0].size();
		vector<vector<int>> len(rows, vector<int>(cols, 0));
		int maxlen = 0;
		for (int i = 0; i < rows; i++){
			len[i][0] = matrix[i][0] - '0';
			if (len[i][0] == 1)
				maxlen = 1;
		}
		for (int i = 0; i < cols; i++){
			len[0][i] = matrix[0][i] - '0';
			if (len[0][i] == 1)
				maxlen = 1;
		}
		for (int i = 1; i < rows; i++){
			for (int j = 1; j < cols; j++){
				if (matrix[i][j] == '0')
					len[i][j] = 0;
				else{
					len[i][j] = min(min(len[i - 1][j], len[i][j - 1]), len[i - 1][j - 1]) + 1;
					if (len[i][j]>maxlen)
						maxlen = len[i][j];
				}
			}
		}
		return maxlen*maxlen;
	}
};