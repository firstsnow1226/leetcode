class Solution {
    static const int MAXN = 100005;
    long long cnt[MAXN];
public:
    bool check(long long x,long long k,int n,int r){
        long long tmp[MAXN];
        for(int i=0;i<n;i++)
            tmp[i] = cnt[i];
        long long sum = 0;
        long long use = 0;
        for(int i=0;i<=r;i++)
            sum += tmp[i];

        for(int i=0;i<n;i++){
            if( sum < x ){
                tmp[min(i+r,n-1)] += (x-sum);
                use += (x-sum);
                sum = x;
            }
            sum += ((i+r+1<n)? tmp[i+r+1]:0);
            sum -= ((i-r>=0)? tmp[i-r]:0);
            if( use > k )
                return false;
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long sum = 0;
        for(int i=0;i<n;i++)
            cnt[i] = stations[i];

        long long L = 0;
        long long R = 1e12;
        long long ans;
        while( L <= R ){
            long long M = (L+R)/2;
            if( check(M,(long long)k,n,r) ){
                L = M + 1;
                ans = M;
            }
            else{
                R = M - 1;
            }
        }


        return ans;
    }
};
