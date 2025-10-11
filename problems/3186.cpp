typedef long long int ll;
const int MAXN = 100005;
#define P pair<ll,ll>
#define F first
#define S second
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        
        priority_queue<P> pq;
        for(auto x:power){
            if( pq.empty() ){
                pq.push({x,x});
                continue;
            }
            vector<P> tmp;
            bool find = false;
            while(!pq.empty()){
                tmp.push_back(pq.top());
                pq.pop();
                if( x == tmp.back().S ){
                    tmp.back().F += x;
                    find = true;
                    break;
                }
                if( x - tmp.back().S > 2 ){
                    pq.push({tmp.back().F+x,x});
                    find = true;
                    break;
                }
            }
            for(auto y:tmp)
                pq.push(y);
            if( !find )
                pq.push({x,x});
        }
        return pq.top().F;

    }
};
