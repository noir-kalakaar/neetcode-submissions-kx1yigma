class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea,dfs(grid,i,j,0));
                }
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, int r, int c, int area){
        if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid[r][c]==0)return 0;
        grid[r][c]=0;
        area++;
        for(int i=0;i<4;i++){
            area+=dfs(grid,r+dir[i][0],c+dir[i][1],0);
        }
        return area;
    }
};


    

    