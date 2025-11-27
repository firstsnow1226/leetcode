class Solution {
    static const long long INF = 1e15;
    static const long long MAXN = 200005;
    long long prs[MAXN];    
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        for(int i=0;i<k;i++)
            prs[i] = INF;
        prs[0] = 0;
        long long ans = -INF;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            long long cnt = sum - prs[(i+1)%k];
            ans = max(ans,cnt);
            prs[(i+1)%k] = min(prs[(i+1)%k],sum); 
        }
        return ans;
    }
};
