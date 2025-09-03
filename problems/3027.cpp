class Solution {
public:
    static const int MAXN = 2002;
    int numberOfPairs(vector<vector<int>>& points) {
        vector<int> nums;
        nums.push_back(-1000000001);
        int N = points.size();
        for(auto x:points){
            nums.push_back(x[0]);
            nums.push_back(x[1]);
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        sort(points.begin(),points.end(),[](vector<int> a, vector<int> b){
            return ((a[0] == b[0]) ? a[1]>b[1] : a[0]<b[0]);
        }
        );
        int prs[nums.size()+1][nums.size()+1];
        memset(prs, 0, sizeof(prs));

        for(auto x:points){
            int x0 = lower_bound(nums.begin(),nums.end(),x[0]) - nums.begin();
            int y0 = lower_bound(nums.begin(),nums.end(),x[1]) - nums.begin();
            prs[ x0 ][ y0 ] = 1;
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=nums.size()-1;j>=0;j--){
                prs[i][j] += prs[i-1][j] +  prs[i][j+1] - prs[i-1][j+1];
            }
        }
        int ans = 0;
        for(int i=0;i<N;i++){
            int x0 = lower_bound(nums.begin(),nums.end(),points[i][0]) - nums.begin();
            int y0 = lower_bound(nums.begin(),nums.end(),points[i][1]) - nums.begin();
            for(int j=i+1;j<N;j++){
                int x1 = lower_bound(nums.begin(),nums.end(),points[j][0]) - nums.begin();
                int y1 = lower_bound(nums.begin(),nums.end(),points[j][1]) - nums.begin();
                if( prs[x1][y1] - prs[x0-1][y1] - prs[x1][y0+1] + prs[x0-1][y0+1] == 2 )
                    ans++;
            }
        }
        return ans;
    }
};
