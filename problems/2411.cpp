class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> pos(31,-1);
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            int tmp = i;
            for(int j=0;j<pos.size();j++){
                if( (nums[i]&(1<<j)) > 0 ){
                    pos[j] = i;
                }
                else if( pos[j] != -1 ){
                    tmp = max(tmp,pos[j]);
                }
            }
            ans.push_back(tmp-i+1);
        }
        vector<int> ans_rev;
        for(int i=ans.size()-1;i>=0;i--)
            ans_rev.push_back(ans[i]);
        return ans_rev;
        
    }
};
