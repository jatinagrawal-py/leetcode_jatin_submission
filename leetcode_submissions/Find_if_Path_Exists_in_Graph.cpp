class Solution {
public:
    int find(int x , vector<int>&parent){
        if(parent[x]==x)return x;

        return parent[x] = find(parent[x],parent);
    }

    void unionn(int x , int y , vector<int>&parent){
        int xp = find(x,parent);
        int yp = find(y,parent);

        if(xp!=yp){
            parent[yp] = xp;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       
        if(source==destination)return true;
        vector<int>parent(n);
        for(int i =0;i<n;i++){
            parent[i] = i;
        }

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            if(find(v,parent)!=find(u,parent)){
                unionn(u,v,parent);
            }
        }

        return find(source,parent)==find(destination,parent);
        
    }
};