#define P pair<int,int> 
#define F first
#define S second

class CountIntervals {
    set<P> st;
    int cnt;
public:
    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        auto it = st.upper_bound({left,INT_MIN});

        if( it != st.begin() && (--it)->S < left ){
            it++;
        }
        while( it != st.end() && it->F <= right ){
            left = min(left,it->F);
            right = max(right,it->S);

            cnt -= (it->S-it->F+1);
            it = st.erase(it);
        }
        st.insert({left,right});
        cnt += (right-left+1);
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
