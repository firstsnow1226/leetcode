#define P pair<int,int>
#define F first
#define S second
class Solution {
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    static const int MAXN = 200;
    bool visited[MAXN][MAXN];
    vector<vector<int>> H;
public:
    bool f(int x,int y, int n, int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                visited[i][j] = 0;
        }
        deque<P> dq;
        dq.push_back({x,y});
        visited[x][y] = 1;

        bool up_left = false;
        bool down_right = false;
        while( !dq.empty() and (!up_left or !down_right) ){
            P now = dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++){
                int nxt_x = now.F + dx[i];
                int nxt_y = now.S + dy[i];

                if( nxt_x < 0 or nxt_y < 0 ){
                    up_left = true;
                    continue;
                }
                if( nxt_x >= n or nxt_y >= m ){
                    down_right = true;
                    continue;
                }
                if( visited[nxt_x][nxt_y] or (H[nxt_x][nxt_y] > H[now.F][now.S]) ) continue;
                visited[nxt_x][nxt_y] = 1;
                dq.push_back({nxt_x,nxt_y});
            }
        }
        

        return (up_left and down_right);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        H = heights;
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( f(i,j,n,m) ){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
