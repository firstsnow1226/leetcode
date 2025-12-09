typedef long long int ll;
class Solution {
    const ll MOD = 1e9 + 7;  
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> L, R;
        for(auto x:nums){
            R[x]++;
        }
        ll ans = 0;
        for(auto x:nums){
            R[x]--;
            ll LN = L[2*x];
            ll RN = R[2*x];
            ans += LN*RN;
            L[x]++;
            ans %= MOD;
        }
        return (int)ans;

    }
};
