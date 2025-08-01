class Solution {
public:
    int maxL = 20;
    vector<string> words;
    bool find = false;
    bool checked[305] = {0};
    string s2;
    void check(int p){
        if( find or checked[p]) return;
        checked[p] = 1;
        if( p == s2.length() ){
            find = true;
        }
        string ss = "";
        int e = min(maxL,(int)s2.length()-p);
        for(int i=0;i<e;i++){
            if( find ) break;
            ss += s2[p+i];
            int pos = lower_bound(words.begin(),words.end(),ss)-words.begin();
            if( pos == words.size() or ss != words[pos] ){
                continue;
            }
            check(p+i+1);
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(),wordDict.end());
        for(auto x:wordDict)
            words.push_back(x);
        s2 = s;
        check(0);
        return find;
    }
};
