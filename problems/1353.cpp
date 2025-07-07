#define MAXD 100000
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int> > pq;

        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int now_event = 0;
        int ans = 0;
        for(int i=1;i<=MAXD;i++){
            while(now_event < events.size()){
                if( events[now_event][0] <= i ){
                    pq.push(events[now_event][1]);
                    now_event++;
                }
                else{
                    break;
                }
            }
            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }

            if(!pq.empty() && pq.top() >= i ){
                pq.pop();
                ans++;
            }

        }


        return ans;
    }
};
