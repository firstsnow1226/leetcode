#define MAXN 2005
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int appear[26] = {0};
        string ans = "";
        for(auto x:s){
            appear[x-'a']++;
        }
        vector<char> candidate;
        for(int i=25;i>=0;i--){
            if( appear[i] >= k )
                candidate.push_back('a'+i);
        }
        queue<string> q;
        for(char ch:candidate){
            q.push(string(1,ch));
        }

        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if( curr.size() > ans.size() ){
                ans = curr;
            }
            for(char ch:candidate){
                string nxt = curr + ch;
                if( FindKRepeat(s,nxt,k) ){
                    q.push(nxt);
                }
            }
        }
        return ans;
    }

    bool FindKRepeat(string s,string nxt,int k){
        int repeat_cnt = 0;
        int nxt_ptr = 0;
        int s_ptr = 0;
        while(s_ptr<s.length()){
            if( s[s_ptr] == nxt[nxt_ptr] ){
                nxt_ptr++;
            }
            s_ptr++;
            if( nxt_ptr == nxt.length() ){
                nxt_ptr = 0;
                repeat_cnt++;
            }
            if( repeat_cnt == k ){
                return true;
            }
        }
        return false;
    }
};
