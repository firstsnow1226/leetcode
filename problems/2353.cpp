#define P pair<int,string>
#define F first
#define S second

class FoodRatings {
    static const int MAXN = 20005;
    int N;
    map<string,int> cuisine2type;
    map<string,int> food2num;
    set<P> st[MAXN];
    vector<string> cuisines_cp;
    vector<int> ratings_cp;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        N = foods.size();
        int mp_ptr = 0;
        for(int i=0;i<N;i++){
            if( cuisine2type.find(cuisines[i]) == cuisine2type.end() ){
                cuisine2type[cuisines[i]] = mp_ptr;
                food2num[foods[i]] = i;
                st[mp_ptr].insert({-ratings[i],foods[i]});
                mp_ptr += 1;
                continue;
            }
            int type = cuisine2type[cuisines[i]];
            food2num[foods[i]] = i;
            st[type].insert({-ratings[i],foods[i]});
        }
        cuisines_cp = cuisines;
        ratings_cp = ratings;
    }
    
    void changeRating(string food, int newRating) {
        int num = food2num[food];
        int type = cuisine2type[cuisines_cp[num]];
        int org_rating = ratings_cp[num];
        auto it = st[type].lower_bound({-org_rating,food});
        st[type].erase(it);
        st[type].insert({-newRating,food});
        ratings_cp[num] = newRating;
    }
    
    string highestRated(string cuisine) {
        int type = cuisine2type[cuisine];
        auto it = st[type].begin();
        return it->S;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
