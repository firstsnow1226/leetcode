class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double enf = 1e-5;
        double L = 2e9;
        double R = 0;
        for(const auto& sq : squares){
            L = min(L, (double)sq[1]);
            R = max(R, (double)sq[1]+sq[2]);
        }
        double ans = 0;
        while( R-L > enf ){
            double M = (L+R) / 2;
            double up = 0;
            double down = 0;
            for(const auto& sq : squares){
                double y = sq[1];
                double w = sq[2];
                if( y + w <= M )
                    down += w*w;
                else if( y >= M )
                    up += w*w;
                else{
                    down += w*(M-y);
                    up += w*(y+w-M);
                }
            }

            if( up > down )
                L = M;
            else{
                R = M;
            }
            ans = M;
        }
        return ans;
    }
};
