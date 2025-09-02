class Solution {
public:
    static const int MAXN = 100005;
    static const int offset = 50000;
    int bit[MAXN] = {0};

    int query(int x){
        int cnt = 0;
        for(;x>0;x-=(x&-x))
            cnt += bit[x];
        return cnt;
    }
    void update(int x){
        for(;x<MAXN;x+=(x&-x))
            bit[x]++;
        return;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        ans.resize(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            int now = nums[i] + offset;
            int cnt = query(now-1);
            ans[i] = cnt;
            update(now);
        }
        return ans;
    }
};
