struct node{
    int h, x, y;
    node(int a, int b, int c):
        h(a), x(b), y(c) {}
};
struct cmp{
    bool operator() ( node a, node b ){      
        return a.h > b.h; // 由小排到大
    }
};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int M = heightMap.size();
        int N = heightMap[0].size();

        bool visited[200][200]={0};
        priority_queue<node, vector<node>, cmp> pq;

        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if( i==0 or j==0 or i==M-1 or j==N-1 ){
                    node A(heightMap[i][j],i,j);
                    pq.push(A);
                    visited[i][j] = 1;
                }
            }
        }

        int ans = 0; 
        while(!pq.empty()){
            node now = pq.top();
            pq.pop();

            for(int i=0;i<4;i++){
                int nxt_x = now.x + dx[i];
                int nxt_y = now.y + dy[i];

                if( nxt_x<0 or nxt_x>=M or nxt_y<0 or nxt_y>=N or 
                    visited[nxt_x][nxt_y] )
                    continue;
                
                if( heightMap[nxt_x][nxt_y] < heightMap[now.x][now.y] ){
                    ans += heightMap[now.x][now.y] - heightMap[nxt_x][nxt_y];
                    heightMap[nxt_x][nxt_y] = heightMap[now.x][now.y];
                }
                node nxt(heightMap[nxt_x][nxt_y],nxt_x,nxt_y);
                pq.push(nxt);
                visited[nxt_x][nxt_y] = 1;
            }
        }
        return ans;
    }
};
