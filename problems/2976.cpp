#define P pair<long long,long long>
#define F first
#define S second
class Solution {
    static const long long INF = 1e16;
    static const int MAXA = 26;
    long long dist[MAXA][MAXA];
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for(int i=0;i<MAXA;i++){
            for(int j=0;j<MAXA;j++){
                if( i == j )
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            }
        }
        for(int i=0;i<original.size();i++){
            dist[original[i]-'a'][changed[i]-'a'] = min(dist[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
        }

        for(long long k=0;k<MAXA;k++){
            for(long long i=0;i<MAXA;i++){
                for(long long j=0;j<MAXA;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<source.size();i++){
            if( dist[source[i]-'a'][target[i]-'a'] == INF )
                return -1;
            ans += dist[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};
