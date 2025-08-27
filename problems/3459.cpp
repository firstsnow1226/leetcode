class Solution {
public:
    int dx[4] = {-1,-1,1,1};
    int dy[4] = {-1,1,1,-1};
    int dp[500][500][5][2];
    vector<vector<int>> arr;
    int n, m;

    bool InRange(int x,int y){
        return (0<=x and x<n and 0<=y and y<m);
    }

    int dfs(int x,int y,int d,bool turn,int target){
        int nxt_x = x + dx[d];
        int nxt_y = y + dy[d];

        if( !InRange(nxt_x,nxt_y) or arr[nxt_x][nxt_y] != target )
            return 0;
        if( dp[nxt_x][nxt_y][d][turn] != -1 )
            return dp[nxt_x][nxt_y][d][turn];
        int maxStep = dfs(nxt_x,nxt_y,d,turn,2-target);
        if(turn){
            maxStep = max(maxStep,dfs(nxt_x,nxt_y,(d+1)%4,false,2-target));
        }
        dp[nxt_x][nxt_y][d][turn] = maxStep + 1;
        return maxStep + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        arr = grid;
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j] == 1 ){
                    for(int k=0;k<4;k++)
                        ans = max(ans,dfs(i,j,k,true,2)+1);
                }
            }
        }
        

        
        return ans;
    }
};
