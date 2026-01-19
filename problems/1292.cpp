class Solution {
    static const int MAXN = 305;
    int prs[MAXN][MAXN];
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int N = mat.size();
        int M = mat[0].size();

        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                if( i == 0 or j == 0 )
                    prs[i][j] = 0;
                else
                    prs[i][j] = mat[i-1][j-1]+prs[i-1][j]+prs[i][j-1]-prs[i-1][j-1];
            }
        }
        int L = 0;
        int R = min(N,M);
        int ans = 0;
        while( L <= R ){
            bool find = false;
            int mid = (L+R)/2;

            for(int i=mid;i<=N;i++){
                if( find ) break;
                for(int j=mid;j<=M;j++){
                    int sum = prs[i][j]-prs[i-mid][j]-prs[i][j-mid]+prs[i-mid][j-mid];
                    if( sum <= threshold ){
                        find = true;
                        break;
                    }
                }
            }
            if( find ){
                ans = mid;
                L = mid+1;
            }
            else
                R = mid-1;
        }
        return ans;
    }
};
