class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();

        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(nums[i]+nums[j] == target){
                    vector<int> ans={i,j};
                    return ans;
                }
            }
        }
        vector<int> ans={0,0};
        return ans; 
    }
};

