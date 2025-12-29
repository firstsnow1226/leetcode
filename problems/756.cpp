class Solution {
    vector<string> allow;
    vector<char> dict[26][26];
    char arr[8][8];
    bool find;
public:
    void dfs(int n, int r, int c){
        if( find )
            return;
        if( r == n+1 ){
            find = true;
            return;
        }
        int left = arr[r - 1][c] - 'A';
        int right = arr[r - 1][c + 1] - 'A';
        for(char target : dict[left][right]){
            arr[r][c] = target;
            if( r + c == n + 1 )
                dfs(n, r+1, 1);
            else
                dfs(n, r, c+1);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        allow = allowed;
        find = false;
        int n = bottom.length();
        for(int i=1;i<=n;i++)
            arr[1][i] = bottom[i-1];
        for(auto& x : allowed){
            dict[x[0] - 'A'][x[1] - 'A'].push_back(x[2]);
        }
        dfs(n, 2, 1);
        return find;
    }
};
