bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
    const long MOD = 1000000007;
public:

    int countTrapezoids(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);

        long ans = 0;
        long sum = 0;
        long cnt = 0;
        long pre = -1e9;
        for(const auto &x : points){
            if( x[1] == pre ){
                cnt++;
            }
            else{
                ans += cnt*(cnt-1)/2*sum;
                sum += cnt*(cnt-1)/2;
                cnt = 1;
                pre = x[1];
                ans %= MOD;
                sum %= MOD;
            }
        }
        ans += cnt*(cnt-1)/2*sum;
        ans %= MOD;
        return (int)ans;
    }
};
