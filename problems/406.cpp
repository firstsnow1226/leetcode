class Solution {
public:
    static const int MAXN = 2005;
    int seg[MAXN<<2];

    void build(int L,int R,int ID){
        if( L == R ){
            seg[ID] = 1;
            return;
        }
        int M = (L+R) >> 1;
        build(L,M,ID<<1);
        build(M+1,R,ID<<1|1);
        seg[ID] = seg[ID<<1] + seg[ID<<1|1];
        return;
    }
    int query(int L,int R,int ID,int tar){
        if( L == R ){
            return L;
        }
        int M = (L+R) >> 1;
        if( tar <= seg[ID<<1] ) return query(L,M,ID<<1,tar);
        else return query(M+1,R,ID<<1|1,tar-seg[ID<<1]);
    }
    void update(int L,int R,int ID,int p){
        if( L == R ){
            seg[ID] = 0;
            return;
        }
        int M = (L+R) >> 1;
        if( p <= M ) update(L,M,ID<<1,p);
        else update(M+1,R,ID<<1|1,p);
        seg[ID] = seg[ID<<1] + seg[ID<<1|1];
        return;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
            [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) return a[0] < b[0]; 
            return a[1] > b[1];                   
        });
        int N = people.size();
        vector<vector<int>> ans;
        ans.resize(N);

        build(1,N,1);

        for(auto x:people){
            int tar = x[1] + 1;
            int p = query(1,N,1,tar);
            ans[p-1] = x;
            update(1,N,1,p);
        }
        return ans;
    }
};
