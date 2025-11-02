#define P pair<int,int>
#define F fist
#define S second
const int MAXN = 100005;
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<int> grid[MAXN];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                grid[i].push_back(0);
        }
        for(auto x:guards)
            grid[x[0]][x[1]] = 1;
        for(auto x:walls)
            grid[x[0]][x[1]] = 2;
        for(int i=0;i<m;i++){
            int now = 0;
            for(int j=0;j<n;j++){
                if( grid[i][j] == 1 ){
                    now = 1;
                    continue;
                }
                if( grid[i][j] == 2 ){
                    now = 0;
                    continue;
                }
                if( grid[i][j] == 0 and now == 1 )
                    grid[i][j] = -1;
            }
        }
        for(int i=0;i<m;i++){
            int now = 0;
            for(int j=n-1;j>=0;j--){
                if( grid[i][j] == 1 ){
                    now = 1;
                    continue;
                }
                if( grid[i][j] == 2 ){
                    now = 0;
                    continue;
                }
                if( grid[i][j] == 0 and now == 1 )
                    grid[i][j] = -1;
            }
        }
        for(int j=0;j<n;j++){
            int now = 0;
            for(int i=0;i<m;i++){
                if( grid[i][j] == 1 ){
                    now = 1;
                    continue;
                }
                if( grid[i][j] == 2 ){
                    now = 0;
                    continue;
                }
                if( grid[i][j] == 0 and now == 1 )
                    grid[i][j] = -1;
            }
        }
        for(int j=0;j<n;j++){
            int now = 0;
            for(int i=m-1;i>=0;i--){
                if( grid[i][j] == 1 ){
                    now = 1;
                    continue;
                }
                if( grid[i][j] == 2 ){
                    now = 0;
                    continue;
                }
                if( grid[i][j] == 0 and now == 1 )
                    grid[i][j] = -1;
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if( grid[i][j] == 0 )
                    ans++;
        }
        return ans;
    }
};
