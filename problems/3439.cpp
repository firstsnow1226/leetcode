class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> spaces;
        spaces.push_back(startTime[0]);
        startTime.push_back(eventTime);
        for(int i=0;i<startTime.size()-1;i++){
            spaces.push_back(startTime[i+1] - endTime[i]);
        }
        int ans = 0;
        int cnt;
        int m = min((int)spaces.size(),k+1);
        for(int i=0;i<m;i++)
            ans += spaces[i];
        cnt = ans;
        for(int i=k+1;i<spaces.size();i++){
            cnt += spaces[i];
            cnt -= spaces[i-k-1];
            ans = max(ans,cnt);
        }

        return ans;
    }
};
