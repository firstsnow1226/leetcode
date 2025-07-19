class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        string now = folder[0];
        vector<string> ans;
        ans.push_back(now);

        for(int i=1;i<folder.size();i++){
            if( (now.compare(0,now.length(),folder[i],0,now.length())) == 0 && folder[i][now.length()] == '/' )
                continue;
            
            now = folder[i];
            ans.push_back(now);
        }
        return ans;
        
    }
};
