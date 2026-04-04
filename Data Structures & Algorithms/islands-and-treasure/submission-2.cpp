class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row1 = grid.size();
        int col1 = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<row1;i++){
            for(int j=0;j<col1;j++){
                if(grid[i][j]==0)q.push({i,j});
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int r = row+dir[i][0];
                int c = col+dir[i][1];
                if(r < 0 || r >= row1 || c < 0 || c >= col1 || grid[r][c] != INT_MAX)continue;
                grid[r][c] = grid[row][col]+1;
                q.push({r,c});
            }
        }

        

    }
    
};
