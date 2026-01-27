#define P pair<int,int>
#define F first
#define S second
class Solution {
    static const int MAXN = 50005;
    const int INF = 1e9;
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<P> to[MAXN];
        for(auto x:edges){
            to[x[0]].push_back({x[1], x[2]});
            to[x[1]].push_back({x[0], 2*x[2]});
        }
        priority_queue<P, vector<P>, greater<P> > pq;
        pq.push({0,0});
        int dp[MAXN];
        for(int i=0;i<n;i++)
            dp[i] = INF;
        dp[0] = 0;
        while( !pq.empty() ){
            P now = pq.top();
            pq.pop();
            if( now.S == n-1 )
                return dp[n-1];

            if( now.F != dp[now.S] )
                continue;

            int node = now.S;
            for(auto nxt:to[node]){
                if( dp[nxt.F] > now.F + nxt.S ){
                    dp[nxt.F] = now.F + nxt.S;
                    pq.push({now.F + nxt.S, nxt.F});
                }
            }
        }
        return -1;
    }
};
