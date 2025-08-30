class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check[27] = {0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if( board[i][j] == '.' ) continue;
                int num = board[i][j] - '1';
                int bit = 1 << num;
                if( check[i] & bit ) return false;
                check[i] |= bit;

                if( check[9+j] & bit ) return false;
                check[9+j] |= bit;

                if( check[18+(i/3)*3+j/3] & bit ) return false;
                check[18+(i/3)*3+j/3] |= bit;
            }
        }
        return true;
    }
};
