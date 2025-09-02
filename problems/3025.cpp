class Solution {
public:
    static const int MAXN = 50;

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> a, vector<int> b){
            return ((a[0] == b[0]) ? a[1]>b[1] : a[0]<b[0]);
        }
        );
        int prs[MAXN+1][MAXN+1];
        memset(prs, 0, sizeof(prs));


        for(auto x:points)
            prs[ x[0] ][ x[1] ] = 1;
        for(int i=0;i<=MAXN;i++){
            for(int j=MAXN;j>=0;j--){
                prs[i][j] += ((i>=1)? prs[i-1][j]:0) + ((j<=49)? prs[i][j+1]:0) - ((i>=1 and j<=49)? prs[i-1][j+1]:0);
            }
        }
        int ans = 0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x0 = points[i][0];
                int y0 = points[i][1];
                int x1 = points[j][0];
                int y1 = points[j][1];
                if( prs[x1][y1] - ((x0>=1)? prs[x0-1][y1]:0) - ((y0<=49)? prs[x1][y0+1]:0) + ((x0>=1 and y0<=49)? prs[x0-1][y0+1]:0) == 2 )
                    ans++;
            }
        }
        return ans;
    }
};
