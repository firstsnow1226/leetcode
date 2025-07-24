#define MAXN 1005
const int INF = 1e9;
class Solution {
public:
    vector<vector<int>> values = vector<vector<int>>(MAXN, vector<int>(MAXN, 0));
    vector<int> to[MAXN];
    int ans = INF;

    int get_ans_from_three(int a, int b, int c){
        int MAX = max(a,max(b,c));
        int MIN = min(a,min(b,c));
        return MAX - MIN;
    }

    int count_xor(int s,int f,vector<int>& nums){
        deque<int> dq;
        dq.push_back(s);
        int cnt = 0;
        bool visited[MAXN] = {0};
        visited[s] = 1;

        while(!dq.empty()){
            int now = dq.front();
            dq.pop_front();
            cnt ^= nums[now];

            for(auto x:to[now]){
                if( x == f or visited[x] )
                    continue;
                dq.push_back(x);
                visited[x] = 1;
            }
        }
        return cnt;
    }

    void bfs(int a, int b, int value_a, int value_b){
        deque<int> dq;
        dq.push_back(a);
        bool visited[MAXN] = {0};
        visited[a] = 1;

        while(!dq.empty()){
            int now = dq.front();
            dq.pop_front();

            for(auto x:to[now]){
                if( x == b or visited[x] )
                    continue;
                int value_c = values[x][now];
                int value_aa = value_a ^ value_c;

                ans = min(ans,get_ans_from_three(value_aa,value_b,value_c));
                dq.push_back(x);
                visited[x] = 1;
            }
        }
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        for(int i = 0; i < MAXN; i++){
            to[i].clear();
            fill(values[i].begin(), values[i].end(), 0);
        }

        for(auto x:edges){
            to[ x[0] ].push_back(x[1]);
            to[ x[1] ].push_back(x[0]);
        }

        for(int i=0;i<edges.size();i++){
            values[edges[i][0]][edges[i][1]] = count_xor(edges[i][0],edges[i][1],nums);
            values[edges[i][1]][edges[i][0]] = count_xor(edges[i][1],edges[i][0],nums);
        }

        for(int i=0;i<edges.size();i++){
            int now1 = edges[i][0];
            int now2 = edges[i][1];

            bfs(now1,now2,values[now1][now2],values[now2][now1]);
            bfs(now2,now1,values[now2][now1],values[now1][now2]);
        }

        
        return ans;
    }
};
