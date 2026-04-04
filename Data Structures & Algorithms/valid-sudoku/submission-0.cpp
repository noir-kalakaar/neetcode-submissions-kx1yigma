class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows, cols;
        map<pair<int,int>,unordered_set<char>> square;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || square[{i/3,j/3}].count(board[i][j]))return 0;
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                square[{i/3,j/3}].insert(board[i][j]);
            }
        }
        return 1;
    }
};
