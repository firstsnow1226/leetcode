class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(long long x:spells){
            long long tar = success / x;
            if( success % x != 0 )
                tar++;
            ans.push_back(potions.end() - lower_bound(potions.begin(),potions.end(),tar) );
        }
        return ans;
    }
};
