const int MAXN = 300005;
int cnt[MAXN];
int diff[MAXN];
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        memset(cnt,0,sizeof(cnt));
        memset(diff,0,sizeof(diff));
        vector<int> arr;
        for(int x:nums){
            arr.push_back(x);
            arr.push_back(x-k);
            arr.push_back(x+k+1);
        }
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());

        for(int x:nums){
            int p1 = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
            int p2 = lower_bound(arr.begin(),arr.end(),x-k) - arr.begin();
            int p3 = lower_bound(arr.begin(),arr.end(),x+k+1) - arr.begin();
            cnt[p1]++;
            diff[p2]++;
            diff[p3]--;
        }

        int ans = 0;
        int tot = 0;
        for(int i=0;i<MAXN;i++){
            tot += diff[i];
            ans = max(ans,cnt[i]+min(tot-cnt[i],numOperations));
        }
        return ans;
    }
};
