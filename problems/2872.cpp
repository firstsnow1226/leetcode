const int MAXN = 30005;
class Solution {
    int ans = 0;
    vector<int> to[MAXN];
    long kk = 0;
    vector<int> value;
public:
    long long dfs(int now, int p){
        long sum = 0;
        sum += value[now];
        for(int nxt:to[now]){
            if( nxt == p )
                continue;
            sum += dfs(nxt, now);
        }
        if( sum % kk == 0 ){
            ans++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for(int i=0;i<n;i++)
            to[i].clear();
        ans = 0;
        kk = k;
        value = values;
        for(auto x:edges){
            to[x[0]].push_back(x[1]);
            to[x[1]].push_back(x[0]);
        }
        dfs(0,-1);
        return ans;
    }
};
