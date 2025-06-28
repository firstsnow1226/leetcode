class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            if( ans.size() < k ){
                ans.push_back(nums[i]);
                continue;
            }
            int min_p = 0;
            for(int j=0;j<k;j++){
                if( ans[j] < ans[min_p] ){
                    min_p = j;
                }
            }
            if( nums[i] > ans[min_p] ){
                ans.erase(ans.begin()+min_p);
                ans.push_back(nums[i]);
            }
            
        }
        return ans;
    }
};
