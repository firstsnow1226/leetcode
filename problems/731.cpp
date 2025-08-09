#define P pair<int,int>
#define F first
#define S second

class MyCalendarTwo {
public:
    static const int MAXN = 1005;
    int dn[MAXN*2];
    vector<P> v;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(int i=0;i<MAXN*2;i++)
            dn[i] = 0;
        v.push_back({startTime,endTime});
        vector<int> nums;
        for(auto x:v){
            nums.push_back(x.F);
            nums.push_back(x.S);
        }
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());

        for(auto x:v){
            int s = lower_bound(nums.begin(),nums.end(),x.F) - nums.begin();
            int e = lower_bound(nums.begin(),nums.end(),x.S) - nums.begin();
            dn[s] ++;
            dn[e] --;
        }
        int cnt = 0;
        for(auto x:dn){
            cnt += x;
            if( cnt >= 3 ){
                v.pop_back();
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
