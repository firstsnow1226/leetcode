class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int cnt = 1;
        int ptr = nums[0]-k;

        for(int i=1;i<nums.size();i++){
            if( nums[i]+k < ptr+1 )
                continue;
            ptr = max(ptr+1,nums[i]-k);
            cnt++;
        }
        return cnt;
    }
};
