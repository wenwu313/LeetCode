class Solution {
public:
    int m, n;
    void filp(vector<vector<char>>& grid, int x, int y) {
        if (x<0 || x >= m || y<0 || y >= n || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        filp(grid, x - 1, y);
        filp(grid, x + 1, y);
        filp(grid, x, y - 1);
        filp(grid, x, y + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    filp(grid, i, j);
                }
            }
        }
        return count;
    }
};