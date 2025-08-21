class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat[0].size();
        vector<int> heights(m,0);
        int ans = 0;
        for(const auto& row : mat){
            for(int i=0;i<m;i++)
                heights[i] = (row[i]==0)? 0: heights[i]+1;

            stack<vector<int>> st;
            st.push({-1,0,-1}); // pos cur h
            for(int i=0;i<m;i++){
                int h = heights[i];
                while( st.top()[2] >= h )
                    st.pop();
                
                auto& top = st.top();
                int p = top[0];
                int prev = top[1];
                int cur = prev + (i-p)*h;
                ans += cur;
                st.push({i,cur,h});
            }
        }
        return ans;
    }
};
