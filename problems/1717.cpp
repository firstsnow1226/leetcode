class Solution {
public:
    int maximumGain(string s, int x, int y) {
        s += 'c';
        vector<char> stk;
        int ans = 0;
        for(char ch:s){
            if(ch != 'a' and ch != 'b'){
                int cnt_a = 0;
                int cnt_b = 0;
                for(auto x:stk){
                    if( x == 'a' ) cnt_a++;
                    else cnt_b++;
                }
                if( !stk.empty() and stk[0] == 'a'){
                    ans += x*min(cnt_a,cnt_b);
                }
                else
                    ans += y*min(cnt_a,cnt_b);
                stk.clear();
            }
            else if( ch == 'a' ){
                if( x >= y )
                    stk.push_back(ch);
                else{
                    if( !stk.empty() && stk.back() == 'b' ){
                        ans += y;
                        stk.pop_back();
                    }
                    else
                        stk.push_back(ch);
                }
            }
            else if( ch == 'b' ){
                if( y >= x )
                    stk.push_back(ch);
                else{
                    if( !stk.empty() && stk.back() == 'a' ){
                        ans += x;
                        stk.pop_back();
                    }
                    else
                        stk.push_back(ch);
                }
            }
            
        }
        return ans;
    }
};
