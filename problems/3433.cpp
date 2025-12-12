class Solution {
    const int MAXN = 105;
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans;
        for(int i=0;i<numberOfUsers;i++)
            ans.push_back(0);
        
        vector<int> off[MAXN];
        for(auto x:events){
            if( x[0] == "OFFLINE" ){
                off[ stoi(x[2]) ].push_back( stoi(x[1]) );
            }
        }
        for(auto x:events){
            if( x[0] == "OFFLINE" )
                continue;
            if( x[2] == "ALL" ){
                for(int i=0;i<numberOfUsers;i++)
                    ans[i]++;
            }
            else if( x[2] == "HERE" ){
                int t = stoi(x[1]);
                for(int i=0;i<numberOfUsers;i++){
                    bool offline = false;
                    for(auto j:off[i]){
                        if( j+60 > t and j <= t )
                            offline = true;
                    }
                    if( !offline )
                        ans[i]++;
                }
            }
            else{
                int ptr = 0;
                string tmp = "";
                while( ptr < x[2].length() ){
                    ptr += 2;
                    while( ptr < x[2].length() and x[2][ptr] != ' ' ){
                        tmp += x[2][ptr];
                        ptr++;
                    }
                    ans[ stoi(tmp) ]++;
                    tmp = "";
                    ptr++;
                }
            }
            
        }

        return ans;
    }
};
