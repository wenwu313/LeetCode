class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows <= 0) return 0;
        int cols = matrix[0].size();
        vector<vector<int>> len(rows, vector<int>(cols, 0));
        int maxlen = 0;
        for (int i = 0; i<rows; i++) {
            len[i][0] = matrix[i][0] - '0';
            maxlen = max(len[i][0], maxlen);
        }
        for (int i = 0; i<cols; i++) {
            len[0][i] = matrix[0][i] - '0';
            maxlen = max(len[0][i], maxlen);
        }
        for (int i = 1; i<rows; i++) {
            for (int j = 0; j<cols; j++) {
                if (matrix[i][j] == '1') {
                    len[i][j] = min(min(len[i - 1][j], len[i][j - 1]), len[i - 1][j - 1]) + 1;
                    maxlen = max(len[i][j], maxlen);
                }
            }
        }
        return maxlen*maxlen;
    }
};