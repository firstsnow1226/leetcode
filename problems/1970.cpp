#define P pair<int,int>
#define F first
#define S second
const int MAXN = 20005;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int L = 0;
        int R = row*col;
        int ans = 0;
        while( L <= R ){
            int M = (L+R)>>1;
            vector<int> arr[MAXN];
            vector<bool> visited[MAXN];
            for(int i=0;i<=row;i++){
                for(int j=0;j<=col;j++){
                    arr[i].push_back(0);
                    visited[i].push_back(0);
                }
            }
            for(int i=0;i<M;i++){
                arr[ cells[i][0] ][ cells[i][1] ] = 1;
            }
            bool reach = false;
            deque<P> dq;
            for(int i=1;i<=col;i++){
                if( arr[1][i] == 0 ){
                    dq.push_back(make_pair(1,i));
                    visited[1][i] = 1;
                }
            }
            while(!dq.empty()){
                P now = dq.front();
                dq.pop_front();

                for(int i=0;i<4;i++){
                    int nxt_x = now.F + dx[i];
                    int nxt_y = now.S + dy[i];
                    if( 1 <= nxt_x and nxt_x <= row and 1 <= nxt_y and nxt_y <= col and arr[nxt_x][nxt_y] == 0 and !visited[nxt_x][nxt_y] ){
                        if( nxt_x == row )
                            reach = true;
                        dq.push_back(make_pair(nxt_x,nxt_y));
                        visited[nxt_x][nxt_y] = 1;
                    }
                }
            }

            if( reach ){
                ans = M;
                L = M + 1;
            }
            else{
                R = M - 1;
            }
        }
        return ans;
    }
};
