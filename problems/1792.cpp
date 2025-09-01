struct Data{
    double num, p, t;
    Data(double nn, double pp, double tt) : num(nn), p(pp), t(tt) {}
};
struct Compare {
    bool operator()(const Data& a, const Data& b) {
        return a.num < b.num;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Data, vector<Data>, Compare> pq;
        for(auto x:classes){
            double n = (double)(x[1]-x[0])/((double)(x[1])*(x[1]+1));
            pq.push( Data(n,(double)x[0],(double)x[1])  );
        }
        for(int i=0;i<extraStudents;i++){
            Data now = pq.top();
            pq.pop();
            double n = (double)(now.t-now.p)/((double)(now.t+1)*(now.t+2));
            pq.push( Data(n,now.p+1,now.t+1) );
        }
        double ans = 0;
        while(!pq.empty()){
            ans += pq.top().p/pq.top().t;
            pq.pop();
        }
        return ans/classes.size();
    }
};
