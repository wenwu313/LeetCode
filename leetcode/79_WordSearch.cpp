class Solution {
public:
	bool dfs(vector<vector<char>>& board, string word, int count, int i, int j, vector<vector<int>> &visited) {
		if (count == word.size() - 1)
			return true;
		visited[i][j] = 1;      //已经访问  
		if (i + 1 < board.size() && visited[i + 1][j] == 0 && board[i + 1][j] == word[count + 1])
			if (dfs(board, word, count + 1, i + 1, j, visited))
				return true;
		if (i - 1 >= 0 && visited[i - 1][j] == 0 && board[i - 1][j] == word[count + 1])
			if (dfs(board, word, count + 1, i - 1, j, visited))
				return true;
		if (j + 1 < board[0].size() && visited[i][j + 1] == 0 && board[i][j + 1] == word[count + 1])
			if (dfs(board, word, count + 1, i, j + 1, visited))
				return true;
		if (j - 1 >= 0 && visited[i][j - 1] == 0 && board[i][j - 1] == word[count + 1])
			if (dfs(board, word, count + 1, i, j - 1, visited))
				return true;
		visited[i][j] = 0;      //失败之后要恢复到未访问的状态
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word.size() == 0)
			return true;
		if (board.empty()) return false;
		int rows = board.size(), cols = board[0].size();
		vector<vector<int>> visited(rows, vector<int>(cols, 0));    //0----unvisited  1----visited 
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (board[i][j] == word[0] && dfs(board, word, 0, i, j, visited))  //开始递归 
					return true;
			}
		}
		return false;
	}
};