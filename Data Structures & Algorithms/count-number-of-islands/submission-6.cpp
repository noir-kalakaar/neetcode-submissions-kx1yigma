class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0 || r>=grid.size() || c>=grid[0].size() || c<0||  grid[r][c]=='0')return;
        grid[r][c]='0';
        for(int i=0;i<4;i++){
                dfs(grid,r+dir[i][0],c+dir[i][1]);
        }
    }
};
