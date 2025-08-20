class Solution {
public:
    static const int MAXN = 100005;
    int bit[MAXN] = {0};

    int qry(int x){
        int cnt = 0;
        for(;x>0;x-=(x&(-x)))
            cnt += bit[x];
        return cnt;
    }
    void update(int x){
        for(;x<MAXN;x+=(x&(-x)))
            bit[x]++;
    }

    int numTeams(vector<int>& rating) {
        int ans = 0;
        int N = rating.size();
        for(int i=0;i<N;i++){
            int cnt = qry(rating[i]);
            for(int j=i+1;j<N;j++){
                if( rating[j] > rating[i] )
                    ans += cnt;
                else
                    ans += i - cnt; 
            }
            update(rating[i]);
        }
        return ans;
    }
};
