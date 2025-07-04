const long long INF = 1e14;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        long long L = 0;
        long long tmp = 1;
        while( tmp < INF ){
            tmp *= 2;
            L++;
        }

        long long cnt = 0;
        while( k > 0 ){
            if( k >= tmp ){
                cnt += operations[L];
                k -= tmp;
            }
            L--;
            tmp /= 2;
        }
        return ('a'+(cnt%26));
    }
};
