class Solution {
public:
    int find(int x , vector<int>&parent){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }

    bool unionn(int x , int y , vector<int>&parent){
        int xp = find(x,parent);
        int yp = find(y,parent);
        if(xp != yp){
            parent[yp] = xp;
            return true;
        }
        return false;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> alice(n+1), bob(n+1);
        for(int i = 1; i <= n; i++){
            alice[i] = i;
            bob[i] = i;
        }

        int usedEdges = 0;

        for(auto &it : edges){
            if(it[0] == 3){
                bool a = unionn(it[1], it[2], alice);
                bool b = unionn(it[1], it[2], bob);
                if(a || b) usedEdges++; 
            }
        }

        for(auto &it : edges){
            if(it[0] == 1){
                if(unionn(it[1], it[2], alice)){
                    usedEdges++;
                }
            }
        }

        for(auto &it : edges){
            if(it[0] == 2){
                if(unionn(it[1], it[2], bob)){
                    usedEdges++;
                }
            }
        }

        int rootAlice = find(1, alice), rootBob = find(1, bob);
        for(int i = 2; i <= n; i++){
            if(find(i, alice) != rootAlice || find(i, bob) != rootBob){
                return -1; 
            }
        }

        return edges.size() - usedEdges;
    }
};
