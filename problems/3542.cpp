class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> pos[100005];
        int n = nums.size();
        for(int i=0;i<n;i++)
            pos[ nums[i] ].insert(i);
        pos[0].insert(100005);
        
        int ans = 0;
        for(int i=1;i<100005;i++){
            if( pos[i].empty() )
                continue;
            auto ptr = pos[i].begin();
            while(ptr != pos[i].end() ){
                auto e = pos[0].upper_bound(*ptr);
                auto now = ptr;
                while( now != pos[i].end() and *now < *e ){
                    now++;
                }
                ptr = now;
                ans++;
            }
            for(auto it=pos[i].begin();it!=pos[i].end();it++)
                pos[0].insert(*it);
        }
        return ans;
    }
};
