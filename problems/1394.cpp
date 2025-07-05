#define MAXN 505
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[MAXN] = {0};
        
        for(auto x:arr)
            cnt[x]++;
        
        int ans = -1;

        for(int i=1;i<MAXN;i++){
            if( cnt[i] == i )
                ans = i;
        }
        return ans;
    }
};
