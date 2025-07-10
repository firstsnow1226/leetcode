class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int max_space = 0;
        vector<bool> q;
        for(int i=0;i<startTime.size();i++){
            if( endTime[i] - startTime[i] <= max_space )
                q.push_back(true);
            else
                q.push_back(false);
            int pre_space = startTime[i] - ((i==0)? 0:endTime[i-1]);
            max_space = max(max_space,pre_space);
        }
        max_space = 0;
        for(int i=startTime.size()-1;i>=0;i--){
            if( endTime[i] - startTime[i] <= max_space )
                q[i] = true;

            int pre_space = ((i==startTime.size()-1)? eventTime:startTime[i+1]) - endTime[i];
            max_space = max(max_space,pre_space);
        }
        int ans = 0;
        for(int i=0;i<q.size();i++){
            int left = startTime[i] - ((i==0)? 0:endTime[i-1]);
            int right = ((i==startTime.size()-1)? eventTime:startTime[i+1]) - endTime[i];
            int cnt = left + right + ((q[i])? endTime[i]-startTime[i] : 0);
            ans = max(ans,cnt);
        }

        return ans;
    }
};
