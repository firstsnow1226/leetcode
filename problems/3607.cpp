class Solution {
    static const int MAXN = 100005;
    int root[MAXN];
public:
    int findroot(int x){
        return (x==root[x])? x:root[x] = findroot(root[x]);
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        for(int i=1;i<=c;i++)
            root[i] = i;
        for(auto x:connections){
            int u = x[0];
            int v = x[1];
            int Ru = findroot(u);
            int Rv = findroot(v);
            if( Ru == Rv )
                continue;
            root[Rv] = Ru;
        }
        set<int> grid[MAXN];
        for(int i=1;i<=c;i++){
            grid[ findroot(i) ].insert(i);
        }
        vector<int> ans;
        for(auto x:queries){
            if( x[0] == 1 ){
                int group = findroot(x[1]);
                if( grid[group].size() == 0 ){
                    ans.push_back(-1);
                }
                else{
                    if( grid[group].count(x[1]) ){
                        ans.push_back(x[1]);
                    }
                    else
                        ans.push_back(*grid[group].begin());
                }
            }
            else{
                int group = findroot(x[1]);
                grid[group].erase(x[1]);
            }
        }
        return ans;
    }
};
