class Solution {
public:
    bool find = false;
    vector<vector<char>> grid;
    vector<vector<char>> ans;

    void place(int x,int y,int check[]){
        if( find ) return;
        if( x == 9 ){
            ans = grid;
            find = true;
            return;
        }
        if( grid[x][y] != '.' ){
            place( ((y==8)? x+1:x) , (y+1)%9 , check );
            return;
        }
        for(int i=1;i<=9;i++){
            int bit = 1 << i;
            if( (check[x] & bit) or (check[9+y] & bit) or (check[18+(x/3)*3+y/3] & bit) ) continue;
            check[x] |= bit;
            check[9+y] |= bit;
            check[18+(x/3)*3+y/3] |= bit;
            grid[x][y] = '0' + i;
            place( ((y==8)? x+1:x) , (y+1)%9 , check );
            check[x] ^= bit;
            check[9+y] ^= bit;
            check[18+(x/3)*3+y/3] ^= bit;
            grid[x][y] = '.';
        }
        return;
    }

    void solveSudoku(vector<vector<char>>& board) {
        grid = board;
        find = false;
        int check[27] = {0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if( board[i][j] == '.' ) continue;
                int num = board[i][j] - '0';
                int bit = 1 << num;
                check[i] |= bit;
                check[9+j] |= bit;
                check[18+(i/3)*3+j/3] |= bit;
            }
        }
        place(0,0,check);
        board = ans;

    }
};
