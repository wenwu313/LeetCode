class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return matrix;
        queue<pair<int, int>> que;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        vector<vector<int>> dirs = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                    que.push({ i,j });
                else
                    res[i][j] = -1;
            }
        }

        while (!que.empty()) {
            pair<int, int> point = que.front();
            int x = point.first, y = point.second;
            que.pop();
            for (int i = 0; i < dirs.size(); i++) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && res[nx][ny] == -1) {
                    res[nx][ny] = res[x][y] + 1;
                    que.push({ nx,ny });
                }
            }
        }
        return res;
    }
};
