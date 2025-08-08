class NumArray {
public:
    static const int MAXN = 30005;
    vector<int> arr;
    int seg[MAXN<<2];
    int N;

    void build(int L,int R,int ID){
        if( L == R ){
            seg[ID] = arr[L];
            return;
        }
        int M = (L+R) >> 1;
        build(L,M,ID<<1);
        build(M+1,R,ID<<1|1);
        seg[ID] = seg[ID<<1] + seg[ID<<1|1];
    }

    NumArray(vector<int>& nums) {
        N = nums.size();
        arr.push_back(0);
        for(auto x:nums)
            arr.push_back(x);
        build(1,N,1);
    }
    
    void seg_update(int L,int R,int ID,int index,int val){
        if( L == R ){
            seg[ID] = val;
            return;
        }
        int M = (L+R) >> 1;
        if( index <= M ) seg_update(L,M,ID<<1,index,val);
        else seg_update(M+1,R,ID<<1|1,index,val);
        seg[ID] = seg[ID<<1] + seg[ID<<1|1];
    }

    void update(int index, int val) {
        seg_update(1,N,1,index+1,val);
    }
    
    int query(int L,int R,int ID,int left,int right){
        if( left <= L and R <= right ){
            return seg[ID];
        }
        int M = (L+R) >> 1;
        if( right <= M ) return query(L,M,ID<<1,left,right);
        else if( left >= M+1 ) return query(M+1,R,ID<<1|1,left,right);
        else return query(L,M,ID<<1,left,right) + query(M+1,R,ID<<1|1,left,right);
    }

    int sumRange(int left, int right) {
        return query(1,N,1,left+1,right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
