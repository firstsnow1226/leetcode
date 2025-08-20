class Solution {
public:
    static const int MAXN = 50005;
    vector<long> num;
    int bit[MAXN] = {0};

    int find_pos(long x){
        int L = 0;
        int R = num.size()-1;
        int p;
        while(L<=R){
            int M = (L+R) >> 1;
            if( num[M] <= x ){
                p = M;
                L = M + 1;
            }
            else
                R = M - 1;
        }
        return p;
    }
    int qry(int x){
        int cnt = 0;
        for(;x>0;x-=(x&(-x))){
            cnt += bit[x];
        }
        return cnt;
    }
    void update(int x){
        for(;x<MAXN;x+=(x&(-x)))
            bit[x]++;
    }

    int reversePairs(vector<int>& nums) {
        num.push_back(-1e12);
        num.push_back(1e12);
        for(auto x:nums)
            num.push_back(x);
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
        

        long ans = 0;
        for(int i=0;i<nums.size();i++){
            int p = find_pos(2ULL*nums[i]);
            int r = find_pos(nums[i]);
            //cout<<p<<' ';
            ans += i - qry(p);
            update(r);
            //cout<<ans<<'\n';
        }
        return ans;
    }
};
