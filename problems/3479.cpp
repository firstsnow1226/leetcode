class Solution {
public:
    static const int MAXN = 100005;
    static const int INF = 1e7;
    int seg[MAXN << 2] = {0};
    vector<int> arr;
    void build(int L, int R, int ID){
        if( L == R ){
            seg[ID] = arr[L];
            return;
        }
        int M = (L + R) >> 1;
        build(L,M,ID<<1);
        build(M+1,R,ID<<1|1);
        seg[ID] = max(seg[ID<<1],seg[ID<<1|1]);
        return;
    }
    int Query(int L, int R, int ID, int v){
        if( seg[ID] < v )
            return INF;
        if( L == R )
            return L;
        int M = (L + R) >> 1;
        int a = Query(L,M,ID<<1,v);
        if( a != INF ) return a;
        return Query(M+1,R,ID<<1|1,v);
    }
    void Update(int L, int R, int ID, int p){
        if( L == R ){
            seg[ID] = 0;
            return;
        }
        int M = (L + R) >> 1;
        if( p <= M ) Update(L,M,ID<<1,p);
        else Update(M+1,R,ID<<1|1,p);
        seg[ID] = max(seg[ID<<1],seg[ID<<1|1]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        arr.push_back(0);
        for(auto x:baskets)
            arr.push_back(x);
        int N = baskets.size();
        build(1,N,1);
        
        int ans = 0;
        for(auto fruit:fruits){
            int p = Query(1,N,1,fruit);
            if( p == INF ){ 
                ans += 1;
                continue;
            }
            arr[p] = 0;
            Update(1,N,1,p);
        }
        return ans;
    }
    
};
