class Solution {
public:
    long long flowerGame(int n, int m) {
        return((long)((n+1)/2)*(long)(m/2)+(long)(n/2)*(long)((m+1)/2));
    }
};
