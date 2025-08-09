class Solution {
public:
    vector<int> nums;
    static const int MAXN = 20005;
    int seg[MAXN<<2], lazy[MAXN<<2]; // lazy tag

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        for(auto x:buildings){
            nums.push_back(x[0]);
            nums.push_back(x[1]);
        }
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int N = nums.size();
        build(1,N,1);

        for(auto x:buildings){
            int s = (lower_bound(nums.begin(),nums.end(),x[0]) - nums.begin()) + 1;
            int e = (lower_bound(nums.begin(),nums.end(),x[1]) - nums.begin());
            //cout<<s<<' '<<e<<' '<<x[2]<<'\n';
            update(1,N,1,s,e,x[2]);
        }
        int prev_h = -1;
        for(int i=1;i<=nums.size();i++){
            int h = query(1,N,1,i);
            if( h == prev_h )
                continue;
            int pos = nums[i-1];
            vector<int> tmp = {pos,h};
            ans.push_back(tmp);
            prev_h = h;
        }

        return ans;
    }
    void build(int L,int R,int ID){
        if( L == R ){
            seg[ID] = 0;
            return;
        }
        int M = (L+R) >> 1;
        build(L,M,ID<<1);
        build(M+1,R,ID<<1|1);
        seg[ID] = max(seg[ID<<1],seg[ID<<1|1]);
        return;
    }
    void pushdown(int ID){
        if( lazy[ID] ){
            lazy[ID<<1] = max(lazy[ID<<1],lazy[ID]);
            lazy[ID<<1|1] = max(lazy[ID<<1|1],lazy[ID]);
            seg[ID<<1] = max(seg[ID<<1],lazy[ID]);
            seg[ID<<1|1] = max(seg[ID<<1|1],lazy[ID]);
            lazy[ID] = 0;
        }
    }

    void update(int L,int R,int ID,int left,int right,int val){
        if( left <= L and R <= right ){
            seg[ID] = max(seg[ID],val);
            lazy[ID] = max(lazy[ID],val);
            return;
        }
        pushdown(ID);
        int M = (L+R) >> 1;
        if( right <= M ) update(L,M,ID<<1,left,right,val);
        else if( left >= M+1 ) update(M+1,R,ID<<1|1,left,right,val);
        else{
            update(L,M,ID<<1,left,right,val);
            update(M+1,R,ID<<1|1,left,right,val);
        }
        seg[ID] = max(seg[ID<<1],seg[ID<<1|1]);
        return;
    }
    int query(int L,int R,int ID,int p){
        if( L == R ){
            return seg[ID];
        }
        pushdown(ID);
        int M = (L+R) >> 1;
        if( p <= M ) return query(L,M,ID<<1,p);
        else return query(M+1,R,ID<<1|1,p);
    }
};
