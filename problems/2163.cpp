#define MAXN 100005
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long n = nums.size()/3;
        long long left[MAXN], right[MAXN];
        priority_queue<long long> pq;
        long long cnt = 0;
        
        for(int i=0;i<n;i++){
            cnt += nums[i];
            pq.push(nums[i]);
        }
        left[0] = cnt;

        for(int i=1;i<=n;i++){
            cnt += nums[i+n-1];
            pq.push(nums[i+n-1]);
            cnt -= pq.top();
            pq.pop();

            left[i] = cnt;
        }

        cnt = 0;
        priority_queue<long long, vector<long long>, greater<long long> > pq2;
        for(int i=nums.size()-1;i>=nums.size()-n;i--){
            cnt += nums[i];
            pq2.push(nums[i]);
        }
        right[n] = cnt;

        for(int i=1;i<=n;i++){
            cnt += nums[nums.size()-n-i];
            pq2.push(nums[nums.size()-n-i]);
            cnt -= pq2.top();
            pq2.pop();

            right[n-i] = cnt;
        }
        
        long long ans = 100000000000;
        for(int i=0;i<=n;i++){
            ans = min(ans,left[i]-right[i]);
        }
        return ans;
    }
};
