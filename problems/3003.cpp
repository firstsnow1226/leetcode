class Solution {
    string ss;
    int kk;
    int ans;
    int c;
public:
    void f(int p, int n, int cnt, bool used, int mask, int pre){
        if( p == ss.length() ){
            int tot = n;
            if( cnt > 0 )
                tot++;
            ans = max(ans,tot);
            return;
        }
        if( !used ){
            if( cnt == kk ){
                int now = c;
                now &= mask;
                f(p+1,n+1,1,1,0,now);
            }
            else
                f(p+1,n,cnt+1,1,mask,-1);
        }

        if( mask & (1<<(ss[p]-'a')) ){
            f(p+1,n,cnt,used,mask,pre);
        }
        else{
            int n_cnt = cnt;
            int n_pre = pre;
            if( n_pre >= 0 ){
                n_pre |=  (1<<(ss[p]-'a'));
                if( n_pre == c ){
                    n_cnt--;
                    n_pre = -1;
                }
            }
            if( n_cnt == kk )
                f(p+1,n+1,1,used,(1<<(ss[p]-'a')),-1);
            else
                f(p+1,n,n_cnt+1,used,mask|(1<<(ss[p]-'a')),n_pre);
        }
        return;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        if( k == 26 ) return 1;
        ss = s;
        kk = k;
        ans = 0;
        c = (1<<26)-1;
        f(0,0,0,0,0,-1);
        return ans;
    }
};
