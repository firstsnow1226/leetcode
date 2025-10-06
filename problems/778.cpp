#define P pair<int,int>
#define F first
#define S second
class Solution {
    vector<vector<int>> arr;
    static const int MAXN = 52;
    bool visited[MAXN][MAXN];
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int N;
public:
    bool check(int h){
        memset(visited,0,sizeof(visited));
        deque<P> dq;
        if( arr[0][0] <= h ){
            dq.push_back({0,0});
            visited[0][0] = 1;
            if( 0 == N - 1 )
                return 1;
        }
        while( !dq.empty() ){
            P now = dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++){
                int nxt_x = now.F + dx[i];
                int nxt_y = now.S + dy[i];
                if( nxt_x < 0 or nxt_x >= N or nxt_y < 0 or nxt_y >= N or 
                visited[nxt_x][nxt_y] or arr[nxt_x][nxt_y] > h )
                    continue;
                if( nxt_x == N-1 and nxt_y == N-1 )
                    return 1;
                visited[nxt_x][nxt_y] = 1;
                dq.push_back({nxt_x,nxt_y});
            }
        }
        return 0;
    }

    int swimInWater(vector<vector<int>>& grid) {
        arr = grid;
        N = grid.size();
        int L = 0;
        int R = N*N-1;
        int ans;
        while( L <= R ){
            int M = (L+R) >> 1;
            if( check(M) ){
                R = M - 1;
                ans = M;
            }
            else
                L = M + 1;
        }
        return ans;
    }
};
