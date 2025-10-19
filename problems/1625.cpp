class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        vector<string> even;
        vector<string> odd;
        string even0 = "";
        string odd0 = "";
        int L = s.length();
        for(int i=0;i<L;i++){
            if( i % 2 == 0 )
                even0 += s[i];
            else
                odd0 += s[i];
        }
        even.push_back(even0);
        odd.push_back(odd0);

        for(int i=1;i<=9;i++){
            string odd_i = "";
            for(char j:odd[0]){
                int tmp = j-'0';
                tmp += i*a;
                tmp %= 10;
                char c = '0'+tmp;
                odd_i += c;
            }
            odd.push_back(odd_i);
        }
        
        if( b % 2 == 1 ){
            for(int i=1;i<=9;i++){
                string even_i = "";
                for(char j:even[0]){
                    int tmp = j-'0';
                    tmp += i*a;
                    tmp %= 10;
                    char c = '0'+tmp;
                    even_i += c;
                }
                even.push_back(even_i);
            }
        }

        vector<string> ans;
        for(int i=0;i<L;i++){
            int off_set = b*i;
            for(string en:even){
                for(string on:odd){
                    string now = "";
                    for(int p=off_set;p<off_set+L;p++){
                        int rp = p%L;
                        if( rp % 2 == 0 ){
                            now += en[rp/2];
                        }
                        else{
                            now += on[rp/2];
                        }
                    }
                    //cout<<now<<'\n';
                    ans.push_back(now);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans[0];
        
    }
};
