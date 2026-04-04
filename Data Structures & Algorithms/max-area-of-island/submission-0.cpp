class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int row = grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) area = max(area,dfs(grid,i,j));
            }
        }
        return area;

    }
    int dfs(vector<vector<int>>& grid,int r, int c){
        if(r<0 || c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0)return 0;
        grid[r][c]=0;
        int ar = 1;
        for(int i=0;i<4;i++){
            ar += dfs(grid,r+dir[i][0],c+dir[i][1]);
        }
        return ar;
    }
};
