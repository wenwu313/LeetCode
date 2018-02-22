class Solution {
public:
    int m, n;
    void flipBFS(vector<vector<char>> &board, int x, int y) {
        queue<pair<int, int>> que;
        que.push({ x, y });
        while (!que.empty()) {
            auto xy = que.front();
            que.pop();
            if (xy.first<m && xy.first >= 0 && xy.second >= 0 && xy.second<n && board[xy.first][xy.second] == 'O') {
                board[xy.first][xy.second] = '#';
                que.push({ xy.first - 1, xy.second });
                que.push({ xy.first + 1, xy.second });
                que.push({ xy.first, xy.second - 1 });
                que.push({ xy.first, xy.second + 1 });
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i<m; i++) {
            flipBFS(board, i, 0);
            flipBFS(board, i, n - 1);
        }
        for (int i = 0; i<n; i++) {
            flipBFS(board, 0, i);
            flipBFS(board, m - 1, i);
        }
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};