const int MAXN = 200005;
vector<int> dest[MAXN];
int dest_ptr[MAXN];
struct Packet{
    int scr, dst, t;
};
deque<Packet> dq;
// change tuple to hash
struct TupleHash {
    size_t operator()(const tuple<int,int,int>& t) const noexcept {
        auto [a,b,c] = t;
        return ((size_t)a * 1315423911u) ^ ((size_t)b * 2654435761u) ^ (size_t)c;
    }
};
unordered_set<tuple<int,int,int>, TupleHash> st;
class Router {
    int dq_maxsize = -1;
    
public:
    Router(int memoryLimit) {
        dq_maxsize = memoryLimit;
        for(int i=0;i<MAXN;i++){
            dest[i].clear();
            dest_ptr[i] = 0;
        }
        while(!dq.empty())
            dq.pop_front();
        st.clear();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(st.find({source,destination,timestamp}) != st.end())
            return false;
        if( dq.size() == dq_maxsize ){
            auto x = dq.front();
            dq.pop_front();
            st.erase({x.scr,x.dst,x.t});
            dest_ptr[x.dst]++;
        }
        dq.push_back( Packet(source,destination,timestamp));
        dest[destination].push_back(timestamp);
        st.insert({source,destination,timestamp});

        return true;
    }
    
    vector<int> forwardPacket() {
        if( dq.empty() )
            return {};
        
        auto x = dq.front();
        dq.pop_front();
        st.erase({x.scr,x.dst,x.t});
        dest_ptr[x.dst]++;
        return {x.scr,x.dst,x.t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int upp = upper_bound(dest[destination].begin()+dest_ptr[destination],dest[destination].end(),endTime) - dest[destination].begin();
        int low = lower_bound(dest[destination].begin()+dest_ptr[destination],dest[destination].end(),startTime) - dest[destination].begin();
        return upp-low;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
