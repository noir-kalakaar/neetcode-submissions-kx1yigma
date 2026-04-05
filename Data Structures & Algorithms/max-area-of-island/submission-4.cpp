class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count = 0;
                if(grid[i][j]==1){
                    dfs(grid,i,j,count);
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid, int r, int c, int& count){
        if(r<0 || r>=grid.size() || c>=grid[0].size() || c<0||  grid[r][c]==0)return;
        grid[r][c]=0;
        count++;
        for(int i=0;i<4;i++){
            dfs(grid,r+dir[i][0],c+dir[i][1],count);
        }
    }
};
