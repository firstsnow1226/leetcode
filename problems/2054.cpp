typedef long long int ll;
#define P pair<ll,ll>
#define F first
#define S second
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<P> endt;
        for(auto x: events){
            P now;
            now.F = x[1];
            now.S = x[2];
            endt.push_back(now);
        }
        sort(endt.begin(),endt.end());
        sort(events.begin(),events.end());

        ll ans = 0;
        int N = events.size();
        int ptr = 0;
        ll max_v = 0;
        for(int i=0;i<N;i++){
            int now_s = events[i][0];
            while( ptr < N and endt[ptr].F < now_s ){
                max_v = max(max_v, endt[ptr].S );
                ptr++;
            }
            ans = max(ans, max_v + events[i][2]);
        }
        return ans;
    }
};
