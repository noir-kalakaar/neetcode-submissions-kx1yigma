class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxarea= 0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
                if(grid[i][j]==1){
                    maxarea = max(maxarea,dfs(grid,i,j));
                }
            }
        }
        return maxarea;
    }

    int dfs(vector<vector<int>>& grid,int r, int c){
        if(r<0 || r==grid.size() || c<0 || c==grid[0].size() || grid[r][c]==0)return 0;
        int area=1;
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            area = area + dfs(grid,r+dir[i][0],c+dir[i][1]);
        }
        return area;
    }

};
