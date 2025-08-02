#define MAXN 100005
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long min_n = basket1[0];
        vector<long long> nums;

        for(long long x:basket1){
            min_n = min(min_n,x);
            nums.push_back(x);
        }
        for(long long x:basket2){
            min_n = min(min_n,x);
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        
        long long cnt1[MAXN] = {0}, cnt2[MAXN] = {0};
        for(long long x:basket1){
            long long p = lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            cnt1[p]++;
        }
        for(long long x:basket2){
            long long p = lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            cnt2[p]++;
        }
        
        deque<long long> dq1, dq2;
        for(int i=0;i<nums.size();i++){
            if( cnt1[i] == cnt2[i] )
                continue;
            if( abs(cnt1[i]-cnt2[i]) % 2 != 0 )
                return -1;
            if( cnt1[i] > cnt2[i] ){
                for(int j=0;j<(cnt1[i]-cnt2[i])/2;j++)
                    dq1.push_back(nums[i]);
            }
            else{
                for(int j=0;j<(cnt2[i]-cnt1[i])/2;j++)
                    dq2.push_back(nums[i]);
            }
        }
        long long ans = 0;
        while(!dq1.empty()){
            if( dq1.front() <= dq2.front() ){
                ans += min(dq1.front(),min_n*2);
                dq1.pop_front();
                dq2.pop_back();
            }
            else{
                ans += min(dq2.front(),min_n*2);
                dq2.pop_front();
                dq1.pop_back();
            }
        }

        return ans;
    }
};
