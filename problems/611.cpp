class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<N;i++){
            if( nums[i] == 0 )
                continue;
            for(int j=i+1;j<N;j++){
                int p = lower_bound(nums.begin(),nums.end(),nums[i]+nums[j]) - nums.begin();
                ans += max(p - j - 1,0);
            }
        }
        return ans;
    }
};
