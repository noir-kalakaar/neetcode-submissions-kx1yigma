class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int numFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)numFresh++;
            }
        }
        int ans=0;
        

        while(numFresh> 0 && !q.empty()){
            int l = q.size();
            for(int i=0;i<l;i++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r = row+dir[i][0];
                int c = col+dir[i][1];
                if(r<0 || c<0 || r==n || c==m || grid[r][c]!=1)continue;
                grid[r][c]=2;
                numFresh--;
                q.push({r,c});
            }}
            ans++;
        }
        if(numFresh)return -1;
        return ans;
    }
};
