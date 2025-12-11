class Solution {
    const int MAXN = 100005;
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> x[MAXN], y[MAXN];
        for(auto now:buildings){
            x[ now[0] ].push_back(now[1]);
            y[ now[1] ].push_back(now[0]);
        }
        for(int i=1;i<=n;i++){
            sort(x[i].begin(),x[i].end());
            sort(y[i].begin(),y[i].end());
        }
        int ans = 0;
        for(auto now:buildings){
            int pos_y = lower_bound(x[now[0]].begin(),x[now[0]].end(),now[1]) - x[now[0]].begin();
            if( pos_y == 0 or pos_y == x[now[0]].size()-1 )
                continue;
            int pos_x = lower_bound(y[now[1]].begin(),y[now[1]].end(),now[0]) - y[now[1]].begin();
            if( pos_x == 0 or pos_x == y[now[1]].size()-1 )
                continue;
            ans++;
        }
        return ans;
    }
};
