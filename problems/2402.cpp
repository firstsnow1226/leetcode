#define MAXN 105
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int cnt[MAXN] = {0};
        long long end[MAXN] = {0};

         sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        for(auto x:meetings){
            int min_room = 0;
            long min = end[0];
            bool find = false;
            for(int i=0;i<n;i++){
                if( end[i] <= x[0]  ){
                    cnt[i]++;
                    end[i] = x[1];
                    find = true;
                    break;
                }
                if( end[i] < min ){
                    min = end[i];
                    min_room = i;
                }
            }
            if( !find ){
                cnt[min_room]++;
                end[min_room] += (long)(x[1]-x[0]);
            }
        }
        int ans = -1;
        int count = 0;
        for(int i=0;i<n;i++){
            if( cnt[i] > count ){
                count = cnt[i];
                ans = i;
            }
        }
        return ans;

    }
};
