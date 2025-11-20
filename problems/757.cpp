bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}
class Solution {
public:

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        vector<int> ans;

        for(auto x:intervals){
            int s = lower_bound(ans.begin(),ans.end(),x[0]) - ans.begin();
            int e = upper_bound(ans.begin(),ans.end(),x[1]) - ans.begin();
            if( e-s == 0 ){
                ans.push_back(x[1]-1);
                ans.push_back(x[1]);
            }
            else if( e-s == 1 ){
                if( ans.back() == x[1] ){
                    ans.pop_back();
                    ans.push_back(x[1]-1);
                    ans.push_back(x[1]);
                }
                else
                    ans.push_back(x[1]);
            }
        }

        return ans.size();
    }
};
