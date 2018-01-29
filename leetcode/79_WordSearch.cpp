class Solution {
public:
	bool dfs(vector<vector<char>>&board, string word, int count, int row, int col, vector<vector<int>> &visited)
	{
		if (count == word.size() - 1)
			return true;
		visited[row][col] = 1;  //已经访问  
		if (row + 1 < board.size() && visited[row + 1][col] == 0 && board[row + 1][col] == word[count + 1])
		if (dfs(board, word, count + 1, row + 1, col, visited))
			return true;
		if (row - 1 >= 0 && visited[row - 1][col] == 0 && board[row - 1][col] == word[count + 1])
		if (dfs(board, word, count + 1, row - 1, col, visited))
			return true;
		if (col + 1 < board[0].size() && visited[row][col + 1] == 0 && board[row][col + 1] == word[count + 1])
		if (dfs(board, word, count + 1, row, col + 1, visited))
			return true;
		if (col - 1 >= 0 && visited[row][col - 1] == 0 && board[row][col - 1] == word[count + 1])
		if (dfs(board, word, count + 1, row, col - 1, visited))
			return true;
		visited[row][col] = 0;  //失败之后要恢复到未访问的状态  
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word.size() == 0)
			return true;
		int row = board.size();
		int col = board[0].size();
		vector<vector<int>>visited(row, vector<int>(col));   //0----unvisited  1----visited 
		if (row == 0 || col == 0)
			return false;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (board[i][j] == word[0]){
					if (dfs(board, word, 0, i, j, visited))//开始递归  
						return true;
				}
			}
		}
		return false;
	}

};