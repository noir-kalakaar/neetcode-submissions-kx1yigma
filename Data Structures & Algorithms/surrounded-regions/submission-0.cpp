class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            dfs(i,0,board);
            dfs(i,m-1,board);
        }
        for(int i=0;i<m;i++){
            dfs(0,i,board);
            dfs(n-1,i,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='g')board[i][j]='O';
            }
        }
    }
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r>=board.size() || r<0 || c>=board[0].size() || c<0 || board[r][c]!='O')return;
        board[r][c] = 'g';
        for(int i=0;i<4;i++){
            dfs(r+dir[i][0],c+dir[i][1],board);
        }
    }
};
