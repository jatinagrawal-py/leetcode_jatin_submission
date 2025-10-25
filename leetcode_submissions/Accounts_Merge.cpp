class Solution {
public:

    int find(int x , vector<int>&parent){
        if(parent[x]==x) return x;

        return parent[x] = find(parent[x],parent);
    }

    void unionn(int x , int y , vector<int>&parent){
        int xp = find(x,parent);
        int yp = find(y,parent);

        if(xp!=yp){
            parent[xp]=yp;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<int>>mpp;
        for(int i = 0;i<accounts.size();i++){
            for(int j = 1;j<accounts[i].size();j++){
                mpp[accounts[i][j]].push_back(i);
            }
        }
        int n = accounts.size();
        vector<int>parent(n,0);
        for(int i =0;i<n;i++)parent[i]=i;

        for(auto it:mpp){
            vector<int>ahh = it.second;
            if(ahh.size()>1){
                for(int i = 1;i<ahh.size();i++){
                    if(find(ahh[i],parent)!=find(ahh[i-1],parent)){
                        unionn(ahh[i],ahh[i-1],parent);
                    }
                }
            }
        }
        unordered_map<int,set<string>>real;
        for(int i = 0;i<n;i++){
            int par = find(i,parent);
            string name = accounts[i][0];
            for(int j = 1;j<accounts[i].size();j++){
                real[par].insert(accounts[i][j]);
            }
        }
        vector<vector<string>>ans;
        for(auto it:real){
            vector<string>temp;
            temp.push_back(accounts[it.first][0]);
            for(auto ahh:it.second){
                temp.push_back(ahh);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};