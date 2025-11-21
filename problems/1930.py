class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                char ss[3];
                ss[0] = ss[2] = (char)'a'+i;
                ss[1] = (char)'a'+j;
                //cout<<s[0]<<' '<<s[1]<<' '<<s[2]<<'\n';

                int ptr = 0;
                for(auto ch:s){
                    if( ch == ss[ptr] ){
                        ptr++;
                        if( ptr == 3 ){
                            ans++;
                            break;
                        }
                        cout<<ptr<<' ';
                    }   
                }
                cout<<'\n';
            }
        }
        return ans;
    }
};
