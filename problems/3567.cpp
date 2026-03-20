class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> ans(N-k+1, vector<int>(M-k+1, 0));

        for(int i=0;i<N-k+1;i++){
            for(int j=0;j<M-k+1;j++){
                vector<int> tmp;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        tmp.push_back(grid[x][y]);
                        sort(tmp.begin(),tmp.end());
                        if( tmp[0] == tmp[tmp.size()-1] ){
                            ans[i][j] = 0;
                            continue;
                        }
                        int cnt = 1000000;
                        for(int i=0;i<tmp.size()-1;i++){
                            int diff = tmp[i+1]-tmp[i];
                            if( diff == 0 )
                                continue;
                            cnt = min(cnt, tmp[i+1]-tmp[i]);
                        }
                        ans[i][j] = cnt;
                    }
                }
            }
        }
        return ans;
    }
};
