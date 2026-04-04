class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        

        int row = grid.size();
        int col = grid[0].size();
        int islands = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0 || r==grid.size() || c<0 || c==grid[0].size() || grid[r][c]=='0')return;
        grid[r][c]='0';
        for(int i=0;i<4;i++){
            dfs(grid, r+dir[i][0], c+dir[i][1]);
        }
    }
};
