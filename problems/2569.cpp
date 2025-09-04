class Solution {
public:
    static const int MAXN = 100005;
    int seg[MAXN<<2];
    int lazy[MAXN<<2] = {0};
    vector<int> arr;

    inline void Inverse(int L,int R,int ID){
        seg[ID] = R-L+1-seg[ID];
        return;
    }
    inline bool isLeaf(int L,int R){
        return (L == R);
    }
    void push2child(int ID){
        lazy[ID<<1] ^= 1;
        lazy[ID<<1|1] ^= 1;
    }

    void build(int L,int R,int ID){
        if( L == R ){
            seg[ID] = arr[L];
            return;
        }
        int M = (L+R) >> 1;
        build(L,M,ID<<1);
        build(M+1,R,ID<<1|1);
        seg[ID] = seg[ID<<1] + seg[ID<<1|1];
        return;
    }
    void update(int L,int R,int ID,int a,int b){
        if(lazy[ID]){
            Inverse(L,R,ID);
            if( !isLeaf(L,R) )
                push2child(ID);
            lazy[ID] = 0;
        }
        if( L > b or R < a ) return;
        if( a <= L and R <= b ){
            Inverse(L,R,ID);
            if( !isLeaf(L,R) )
                push2child(ID);
            return;
        }
        else{
            int M = (L+R) >> 1;
            update(L,M,ID<<1,a,b);
            update(M+1,R,ID<<1|1,a,b);
            seg[ID] = seg[ID<<1] + seg[ID<<1|1];
        }
    }

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        arr = nums1;
        int N = nums1.size();
        build(0,N-1,1);

        vector<long long> ans;
        long long sum = 0;
        for(auto x:nums2)
            sum += x;
        
        for(auto x:queries){
            switch(x[0]){
                case(1): update(0,N-1,1,x[1],x[2]); break;
                case(2): sum += (long long)seg[1] * x[1]; break;
                case(3): ans.push_back(sum); break;
            }
        }
        return ans;
    }
};
