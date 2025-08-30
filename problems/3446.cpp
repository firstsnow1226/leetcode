class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<int> arr[25];
        int N = grid.size();
        vector<vector<int>> ans(N, vector<int>(N,0));
        for(int i=N-1;i>=1-N;i--){
            for(int j=max(0,i);j<N and j-i<N;j++){
                arr[i+N].push_back(grid[j][j-i]);
                //cout<<j<<' '<<j-i<<'\n';
                //cout<<grid[j][i-j]<<' ';
            }
            sort(arr[i+N].begin(),arr[i+N].end());
            if( i>=0 ){
                for(int j=max(0,i);j<N and j-i<N;j++){
                    ans[j][j-i] = arr[i+N].back();
                    arr[i+N].pop_back();
                }
            }
            else{
                int cnt = 0;
                for(int j=max(0,i);j<N and j-i<N;j++){
                    ans[j][j-i] = arr[i+N][cnt];
                    cnt++; 
                }
            }
        }
        
        return ans;
    }
};
