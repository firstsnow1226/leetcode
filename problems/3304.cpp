class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";

        while( ans.length() < k){
            string nxt = ans;
            for(int i=0;i<nxt.length();i++){
                nxt[i] = 'a'+((nxt[i]-'a'+1)%26);
            }
            ans += nxt;
        }
        return ans[k-1];
    }
};
