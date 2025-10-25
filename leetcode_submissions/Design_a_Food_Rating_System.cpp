class FoodRatings {
public:
    // cusine ->  food -> rating
    // change rating -> map mai hi kar lena na sidha direct
    // // cusine -> highest rating wala rakhenge as a value
    //
    unordered_map<string,int>food_rating;
    unordered_map<string,string>food_c;
    map<string,set<pair<int,string>>>c_foodset;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0;i<foods.size();i++){
            food_rating[foods[i]]=ratings[i];
            food_c[foods[i]]=cuisines[i];
            c_foodset[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int purani = food_rating[food];
        food_rating[food] = newRating;
        c_foodset[food_c[food]].erase({-purani,food});
        c_foodset[food_c[food]].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return (begin(c_foodset[cuisine])->second);
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */