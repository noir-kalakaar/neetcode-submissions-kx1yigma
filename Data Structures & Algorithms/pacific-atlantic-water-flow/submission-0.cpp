class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m));
        vector<vector<bool>> atlantic(n,vector<bool>(m));

        for(int i=0;i<n;i++){
            dfs(i,0,pacific,heights);
            dfs(i,m-1,atlantic,heights);
        }
        for(int i=0;i<m;i++){
            dfs(0,i,pacific,heights);
            dfs(n-1,i,atlantic,heights);
        }
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j])res.push_back({i,j});
            }
        }
        return res;


    }
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && !ocean[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,ocean,heights);
            }
        }
    }
};
