class Solution {
public:
    const int maxN = 1000;
    int lengthOfLongestSubstring(string s) {
        int L = s.length();

        bool Exist[maxN];
        for(int i=0;i<maxN;i++){
            Exist[i] = 0;
        }
        int ans=0;
        int cnt=0;
        int ptr=0;
        for(int i=0;i<L;i++){
            int pos = 256 + (s[i]-'A');
            if( !Exist[ pos ] ){
                Exist[pos]=1;
            }
            else{
                while(s[ptr]!=s[i]){
                    cnt--;
                    Exist[ 256 + (s[ptr]-'A') ]=0;
                    ptr++;
                }
                cnt--;
                ptr++;
            }
            cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
