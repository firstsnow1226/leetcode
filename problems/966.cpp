class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        for(auto qry:queries){
            string best = "";
            int best_priority = 0;
            for(auto word:wordlist){
                if( qry.size() != word.size() )
                    break;
                int priority = 3;
                for(int i=0;i<qry.size();i++){
                    char ch = qry[i];
                    char ch2 = word[i];
                    if( ch == ch2 )
                        continue;
                    else if( abs(ch-ch2) == abs( 'a'-'A' ) )
                        priority = min(priority,2);
                    else if( (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') and (ch2 == 'a' or ch2 == 'e' or ch2 == 'i' or ch2 == 'o' or ch2 == 'u' or ch2 == 'A' or ch2 == 'E' or ch2 == 'I' or ch2 == 'O' or ch2 == 'U') )
                        priority = min(priority,1);
                    else{
                        priority = -1;
                        break;
                    }
                }
                if( priority > best_priority ){
                    best_priority = priority;
                    best = word;
                }
                if( best_priority == 3 )
                    break;
            }
            ans.push_back(best);
        }
        return ans;
    }
};
