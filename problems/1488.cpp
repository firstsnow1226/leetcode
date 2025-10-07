class Solution { 
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> mp;    
        vector<int> ans = vector<int>(rains.size(),-2);       
        set<int> dry;

        for(int i=0;i<rains.size();i++){
            int x = rains[i];
            if( x == 0 ){
                dry.insert(i);
                continue;
            }
            auto last = mp.find(x);
            if( last != mp.end() ){
                auto it = dry.lower_bound(last->second);
                if( it == dry.end() ){
                    return {};
                }
                ans[ *it ] = x;
                dry.erase(it);
            }
            ans[i] = -1;
            mp[x] = i;
        }
        for(int i=0;i<ans.size();i++){
            if( ans[i] == -2 )
                ans[i] = 1;
        }

        return ans;
    }
};
