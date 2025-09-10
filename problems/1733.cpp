class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> no_con;
        for(auto friendship : friendships){
            unordered_map<int, int> mp;
            bool con = false;
            for(int lan : languages[friendship[0]-1]){
                mp[lan] = 1;
            }
            for(int lan : languages[friendship[1]-1]){
                if( mp[lan] ){
                    con = true;
                    break;
                }
            }
            if( !con ){
                no_con.insert(friendship[0]-1);
                no_con.insert(friendship[1]-1);
            }
        }
        int max_cnt = 0;
        vector<int> cnt(n+1,0);

        for(auto x : no_con){
            for(int lan : languages[x]){
                cnt[lan]++;
                max_cnt = max(max_cnt,cnt[lan]);
            }
        }
        return no_con.size()-max_cnt;

        
    }
};
