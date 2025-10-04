class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> h;
        vector<int> p;
        int ans = 0;
        for(int i=0;i<height.size();i++){
            int now_h = height[i];
            if( h.empty() or now_h > h.back() ){
                h.push_back(now_h);
                p.push_back(i);
                continue;
            }
            
            int pos = lower_bound(h.begin(),h.end(),now_h) - h.begin();
            ans = max(ans,now_h*(i-p[pos]));
        }
        
        h.clear();
        p.clear();
        for(int i=height.size()-1;i>=0;i--){
            int now_h = height[i];
            if( h.empty() or now_h > h.back() ){
                h.push_back(now_h);
                p.push_back(i);
                continue;
            }
            
            int pos = lower_bound(h.begin(),h.end(),now_h) - h.begin();
            ans = max(ans,now_h*(p[pos]-i));
        }
        
        return ans;
    }
};
