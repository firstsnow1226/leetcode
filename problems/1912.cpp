#define P pair<int,int>
#define F first
#define S second

const int MAXM = 100005;
set<P> movies[MAXM];
map<P,int> mp;
set<tuple<int,int,int>> rented;


class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i=0;i<MAXM;i++)
            movies[i].clear();
        mp.clear();
        rented.clear();
        for(auto x:entries){
            movies[ x[1] ].insert({x[2],x[0]});
            mp[{x[0],x[1]}] = x[2];
        }        
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        auto it=movies[movie].begin();
        for(int i=0;i<5 and it!=movies[movie].end();i++){
            ans.push_back(it->S);
            it++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = mp[{shop,movie}];
        rented.insert({price,shop,movie});
        movies[movie].erase({price,shop});
    }
    
    void drop(int shop, int movie) {
        int price = mp[{shop,movie}];
        rented.erase({price,shop,movie});
        movies[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        auto it=rented.begin();
        for(int i=0;i<5 and it!=rented.end();i++){
            auto [a,b,c] = *it;
            ans.push_back({b,c});
            it++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
