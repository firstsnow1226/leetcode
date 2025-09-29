class Solution {
    static const int INF = 1e9;
    vector<int> arr;
    int dp[55][55];
public:
    int f(int L,int R){
        if( dp[L][R] != -1 )
            return dp[L][R];
        if( R - L < 2 ){
            dp[L][R] = 0;
            return 0;
        }
        int v1 = arr[L];
        int v2 = arr[R];
        int cnt = INF;
        for(int i=L+1;i<R;i++){
            cnt = min(cnt,f(L,i)+f(i,R)+v1*v2*arr[i]);
        }
        dp[L][R] = cnt;
        return cnt;
    }

    int minScoreTriangulation(vector<int>& values) {
        arr = values;
        memset(dp,-1,sizeof(dp));
        return f(0,values.size()-1);
    }
};
