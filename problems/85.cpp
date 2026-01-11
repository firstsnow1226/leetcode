class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        
        vector<int> heights(M, 0);
        int maxArea = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            stack<int> st; // increasing
            for (int j = 0; j <= M; j++) {
                int currentHeight = (j == M) ? 0 : heights[j];
                
                while (!st.empty() && currentHeight < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                st.push(j);
            }
        }

        return maxArea;
    }
};
