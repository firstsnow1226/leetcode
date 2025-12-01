class Solution {
    vector<int> battery;
public:
    bool check(long long x, int n){
        long long sum = 0;
        for(long long now:battery){
            sum += min(now, x);
        }
        if( sum >= x*n )
            return true;
        return false;

    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long L = 0;
        long long R = 1e14;
        long long ans = -1;
        battery = batteries;
        while( L <= R ){
            long long M = (L+R) >> 1;
            if( check(M, n) ){
                ans = M;
                L = M + 1;
            }
            else
                R = M - 1;
        }
        return ans;
    }
};
