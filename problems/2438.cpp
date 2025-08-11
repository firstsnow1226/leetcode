typedef long long int ll;
class Solution {
public:
    const ll MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> powers;
        ll now = 1;
        while(n>0){
            if( n&1 )
                powers.push_back(now);
            n /= 2;
            now *= 2;
        }
        vector<int> ans;
        for(auto query:queries){
            ll cnt = 1;
            for(int i=query[0];i<=query[1];i++){
                cnt *= powers[i];
                cnt %= MOD;
            }
            ans.push_back((int)(cnt));
        }
        
        return ans;
    }
};
