class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool used[101] = {0};
        int ans = 0;
        for(auto x:nums){
            if( x > 0 and !used[x] ){
                ans += x;
                used[x] = 1;
            }
        }
        if( ans == 0 and nums.back()!=0 ){
            ans = nums.back();
        }

        return ans;
    }
};
