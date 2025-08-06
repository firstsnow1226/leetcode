class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for(auto num:nums){
            if( res.empty() ){
                res.push_back(num);
                continue;
            }
            int p = lower_bound(res.begin(),res.end(),num) - res.begin();
            if( p == res.size() )
                res.push_back(num);
            else
                res[p] = num;
        }
        return res.size();
    }
};
