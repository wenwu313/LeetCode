class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {  
    if (matrix.empty())  
        return matrix;  
    int len1 = matrix.size(), len2 = matrix[0].size();  
    vector<vector<int>> res(len1, vector<int>(len2, 0));  
    typedef pair<int, int> tp;  
    queue<tp> que;  
    for (int i = 0; i < len1; i++){  
        for (int j = 0; j < len2; j++){  
            if (matrix[i][j] == 0)  
                que.push(tp(i, j));  
            else{  
                res[i][j] = -1;  
            }  
        }  
  
    }  
    vector<tp> dirs = { tp(-1, 0), tp(1, 0), tp(0, -1), tp(0, 1) };  
    while (!que.empty()){  
        tp point = que.front();  
        que.pop();  
        int x = point.first, y = point.second;  
        for (int i = 0; i < dirs.size(); i++){             
            int nx = x + dirs[i].first, ny = y + dirs[i].second;  
            if (nx >= 0 && nx <len1 && ny >= 0 && ny < len2 && res[nx][ny] == -1){  
                res[nx][ny] = res[x][y] + 1;  
                que.push(tp(nx, ny));  
            }  
        }  
    }  
    return res;  
}
};