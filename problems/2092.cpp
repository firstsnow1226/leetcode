const int MAXN = 1e5+5;
bool know[MAXN];
int root[MAXN];

bool cmp(const vector<int>& a, const vector<int>& b){
    return a[2] < b[2];
}

int findroot(int x){
    return (x == root[x])? x : root[x] = findroot(root[x]);
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),cmp);
        for(int i=0;i<n;i++)
            know[i] = 0;

        int ptr = 0;
        int M = meetings.size();
        know[0] = know[firstPerson] = 1;
        while( ptr < M ){
            int t = meetings[ptr][2];
            vector<int> p;
            root[0] = 0;
            int ptr2 = ptr;
            while( ptr2 < M and meetings[ptr2][2] == t ){
                int n1 = meetings[ptr2][0];
                int n2 = meetings[ptr2][1];
                
                p.push_back(n1);
                p.push_back(n2);

                if( know[n1] )
                    root[n1] = 0;
                else
                    root[n1] = n1;
                if( know[n2] )
                    root[n2] = 0;
                else
                    root[n2] = n2;
                ptr2++;
            }
            for(int i=ptr;i<ptr2;i++){
                int n1 = meetings[i][0];
                int n2 = meetings[i][1];
                int r1 = findroot(n1);
                int r2 = findroot(n2);
                root[r2] = r1;
            }
            for(auto x: p){
                if( findroot(x) == findroot(0) )
                    know[x] = 1;
            }
            ptr = ptr2;
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if( know[i] )
                ans.push_back(i);
        }
        return ans;
    }
};
