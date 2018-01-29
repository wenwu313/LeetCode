class Solution {
public:
    int rows,cols;
    vector<vector<int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
      
    int dfs(vector<vector<int>>& matrix,int x0,int y0,vector<vector<int>>& path){
        if(path[x0][y0]) return path[x0][y0];
        int maxlen =1;
        for(int i=0;i<dirs.size();i++){
            int x=x0+dirs[i][0],y=y0+dirs[i][1];
            if(x>=0 && x<rows && y>=0 && y<cols && matrix[x][y]>matrix[x0][y0]){
                int len = 1+ dfs(matrix,x,y,path);
                maxlen = max(len,maxlen);
            }         
        }
        path[x0][y0]=maxlen;
        return maxlen;
    }
     
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        rows = matrix.size();
        cols=matrix[0].size();
        vector<vector<int>> path(rows,vector<int>(cols,0));
        int maxlen =0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int len = dfs(matrix,i,j,path);
                maxlen=max(len,maxlen);
            }
        }
        return maxlen;
    }
};