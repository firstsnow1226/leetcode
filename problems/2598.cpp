class Solution {
    static const int MAXN = 100005;
    int cnt[MAXN];
    long offset = 1e10;
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        memset(cnt, 0, sizeof(cnt));
        for(long x:nums)
            cnt[(x+offset*value)%value]++;
        int min_num = 0;
        int min_cnt = cnt[0];

        for(int i=1;i<value;i++){
            if( cnt[i]<min_cnt ){
                min_cnt = cnt[i];
                min_num = i;
            }
        }
        return value*min_cnt+min_num;
    }
};
