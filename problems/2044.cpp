class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int N = 1<<(nums.size());
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<N;i++){
            int now = i;
            int num = 0;
            for(int last;now>0;now^=last){
                last = now & (-now);
                int pos=__lg(last);
                num |= nums[pos];
            }
            if(num == ans){
                cnt++;
            }
            else if(num > ans){
                ans = num;
                cnt = 1;
            }
        }
        return cnt;
    }
};
