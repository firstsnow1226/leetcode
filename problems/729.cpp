class MyCalendar {
public:
    static const int MAXN = 1005;
    vector<vector<int>> v;
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        for(auto x:v){
            if( startTime <= x[1] and x[0] <= endTime-1 )
                return false;
        }
        vector<int> tmp = {startTime,endTime-1};
        v.push_back(tmp);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
