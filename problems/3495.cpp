class Solution {
public:
    long long count(long long x){
        if( x == 0 ) return 0;
        long long cnt = 0;
        long long now = 1;
        long long num = 1;
        now *= 4;
        while( now <= x ){
            cnt += num * (pow(4,num) - pow(4,num-1));
            num += 1;
            now *= 4;
        }
        cnt += num * (x-pow(4,num-1)+1);
        return cnt;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(long long i=0;i<20;i++)
            cout<<count(i)<<' ';

        for(auto x:queries){
            long long sum = count((long long)x[1]) - count((long long)x[0]-1);
            ans += (sum+1) / 2;
        }
        return ans;
    }
};
