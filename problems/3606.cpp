struct Data{
    string name;
    int type;
};
bool cmp(Data a, Data b){
    return (a.type == b.type )? a.name < b.name : a.type < b.type;
}

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<Data> tmp;
        int N = code.size();
        for(int i=0;i<N;i++){
            bool flag = isActive[i];
            if( code[i] == "" )
                flag = false;
            for(char c:code[i] ){
                if( c == '_' or ('a'<= c and c <='z') or ('A'<= c and c <='Z') or ('0'<= c and c <='9') )
                    continue;
                flag = false;
                break;
            }
            if( flag ){
                Data now;
                now.name = code[i];
                if( businessLine[i] == "electronics" )
                    now.type = 0;
                else if( businessLine[i] == "grocery" )
                    now.type = 1;
                else if( businessLine[i] == "pharmacy" )
                    now.type = 2;
                else if( businessLine[i] == "restaurant" )
                    now.type = 3;
                else
                    continue; 
                tmp.push_back(now);
            }
        }
        sort(tmp.begin(),tmp.end(),cmp);

        vector<string> ans;
        for(auto x:tmp)
            ans.push_back(x.name);
        return ans;
    }
};
