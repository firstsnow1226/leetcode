class Solution {
    static const int MAXN = 505;
    static const long INF = -1e14;
    long dp[MAXN][MAXN];
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        int M = nums2.size();

        bool pos1 = 1;
        bool neg1 = 1;
        int pos_min1 = -INF;
        int neg_max1 = INF;
        for(int i=0;i<N;i++){
            if( nums1[i] >= 0 ){
                neg1 = 0;
                pos_min1 = min(pos_min1, nums1[i]);
            }
            else if( nums1[i] <= 0 ){
                pos1 = 0;
                neg_max1 = max(neg_max1, nums1[i]);
            }
        }
        bool pos2 = 1;
        bool neg2 = 1;
        int pos_min2 = -INF;
        int neg_max2 = INF;
        for(int i=0;i<M;i++){
            if( nums2[i] >= 0 ){
                neg2 = 0;
                pos_min2 = min(pos_min2, nums2[i]);
            }
            else if( nums2[i] <= 0 ){
                pos2 = 0;
                neg_max2 = max(neg_max2, nums2[i]);
            }
        }
        if( pos1 and neg2 ){
            return pos_min1*neg_max2;
        }
        if( pos2 and neg1 ){
            return pos_min2*neg_max1;
        }

        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++)
                dp[i][j] = INF;
        }
        for(int i=0;i<=N;i++)
            dp[i][0] = 0;
        for(int j=0;j<=M;j++)
            dp[0][j] = 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                long tmp = (long)nums1[i-1]*(long)nums2[j-1] + dp[i-1][j-1];
                tmp = max(tmp, dp[i][j-1]);
                tmp = max(tmp, dp[i-1][j]);
                dp[i][j] = max(dp[i][j], tmp);
            }
        }
        return (int)dp[N][M];

    }
};
