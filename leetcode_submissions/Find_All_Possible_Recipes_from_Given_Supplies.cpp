class Solution {
public:

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // 1 recipie bananane ke liye ingreidients hone chaiye aur woh ingredients sare supply mai hone chaiye aur agar suupply mai na ho toh recipie mai hone chaiye -> ingredients -> recipies+supplies 
        unordered_map<string,bool>rec;
        unordered_set<string>sup;

        for(auto it:recipes){
            rec[it]=false;
        }
        for(auto it:supplies){
            sup.insert(it);
        }
        vector<string>ans;
        int count = recipes.size();

        while(count--){
            for(int j = 0 ; j< recipes.size() ; j++){
                if(rec[recipes[j]]==true){
                    continue;
                }
                bool banpaega = true;
                for(int i = 0;i<ingredients[j].size();i++){
                    if(sup.find(ingredients[j][i])==sup.end()){
                        banpaega = false;
                        break;
                    }
                }

                if(banpaega==true){
                    sup.insert(recipes[j]);
                    rec[recipes[j]]=true;
                    ans.push_back(recipes[j]);
                }
            }
        }

        return ans;
    }
};