class Solution {
public:
    vector<vector<int>> arr;
    int divide(int x1, int y1, int x2, int y2, int N){
        if( N == 1 ){
            int min_n, max_n, min_m, max_m;
            min_n = min_m = 100;
            max_n = max_m = -1;
            for(int i=x1;i<=x2;i++){
                for(int j=y1;j<=y2;j++){
                    if( arr[i][j] == 1 ){
                        min_n = min(min_n,i);
                        min_m = min(min_m,j);
                        max_n = max(max_n,i);
                        max_m = max(max_m,j);
                    }
                }
            }
            if( max_n == -1 ) return 0;
            return (1+max_n-min_n)*(1+max_m-min_m);
        }
        int cnt = 1000;
        for(int i=x1;i<x2;i++){
            for(int j=1;j<N;j++){
                int area = divide(x1,y1,i,y2,j) + divide(i+1,y1,x2,y2,N-j);
                cnt = min(cnt,area);
            }
        }
        for(int i=y1;i<y2;i++){
            for(int j=1;j<N;j++){
                int area = divide(x1,y1,x2,i,j) + divide(x1,i+1,x2,y2,N-j);
                cnt = min(cnt,area);
            }
        }
        return cnt;
    }

    int minimumSum(vector<vector<int>>& grid) {
        arr = grid;
        

        return divide(0,0,grid.size()-1,grid[0].size()-1,3);
    }
};
