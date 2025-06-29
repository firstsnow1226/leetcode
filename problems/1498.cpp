typedef long long int ll;
const ll MOD = 1000000007;
#define MAXL 100005
class Solution {
public:
    int pow[MAXL];

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        pow[0] = 1;
        for(int i=1;i<MAXL;i++){
            pow[i] = pow[i-1]*2;
            pow[i] %= MOD;
        }

        ll ans = 0;
        for(int i=0;i<nums.size();i++){
            int p = upper_bound(nums.begin(),nums.end(),target-nums[i]) - nums.begin();
            p--;
            
            if( p < i ) continue;
            ans += pow[p-i];
            ans %= MOD;
        }


        return ans;
    }
};
