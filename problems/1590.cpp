typedef long long int ll;
const ll MAXN = 100005;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<ll, ll> mp;
        ll sum = 0;
        for(auto x:nums)
            sum += x;
        if( sum % p == 0 )
            return 0;
        ll re = sum % p;

        ll tot = 0;
        ll ans = MAXN;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            tot += nums[i];
            if( mp.count( (tot+p-re)%p ) ){
                ans = min(ans,i-mp[(tot+p-re)%p]);
            }
            mp[tot%p] = i;
        }
        if( ans == MAXN or ans == nums.size() )
            return -1;
        return ans;
    }
};
