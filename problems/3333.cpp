typedef long long int ll;
const ll mod = 1000000007;
class Solution {
public:
    int possibleStringCount(string word, int k) {
        ll n = word.length(), cnt = 1;
        vector<ll> freq;

        for(int i=1;i<n;i++){
            if( word[i] == word[i-1] )
                cnt++;
            else{
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        ll ans = 1;
        for(ll x:freq){
            ans *= x;
            ans %= mod;
        }
        if( freq.size() >= k ){
            return ((int)ans);
        }

        vector<ll> f(k), g(k, 1);
        f[0] = 1;

        for(int i=0;i<freq.size();i++){
            vector<ll> f_new(k);

            for(int j=1;j<k;j++){
                f_new[j] = g[j-1];
                if( j-freq[i]-1 >= 0){
                    f_new[j] = (f_new[j]-g[j-freq[i]-1]+mod)%mod;
                }
            }
            vector<ll> g_new(k);
            g_new[0] = f_new[0];
            for(int j=1;j<k;j++){
                g_new[j] = (g_new[j-1]+f_new[j])%mod;
            }
            f = move(f_new);
            g = move(g_new);
            
        }
        
        return ((int)((ans-g[k-1]+mod)%mod));
    }
};
