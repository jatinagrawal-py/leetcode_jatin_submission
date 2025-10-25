class Solution {
public:
    
    int find(int x , vector<int>&parent){
        if(parent[x]==x)return x;

        return parent[x] = find(parent[x],parent);
    }

    void unionn(int x , int y , vector<int>&parent , vector<int>&size){
        int xp = find(x,parent);
        int yp = find(y,parent);

        if(xp!=yp){
            parent[xp]=yp;
            size[yp]+=size[xp];
        }
        return;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int si = r*c;

        vector<int>parent(si,0);
        vector<int>size(si,1);
        vector<vector<int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};

        for(int i = 0;i<si;i++)parent[i]=i;

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]==1){
                    for(auto it:dir){
                        int newi = it[0]+i;
                        int newj = it[1]+j;
                        if(newi<r && newj<c && newi>=0 && newj>=0){
                            int newid = (newi*c) + newj;
                            int id = (i*c) + j;
                            if(grid[newi][newj]==1 && find(id,parent)!=find(newid,parent)){
                                unionn(id,newid,parent,size);
                            }
                        }
                    }
                }
            }
        }

        int count = 0;

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    for(auto it:dir){
                        int newi = it[0]+i;
                        int newj = it[1]+j;
                        if(newi<r && newj<c && newi>=0 && newj>=0){
                            int newid = (newi*c) + newj;
                            int id = (i*c) + j;
                            if(grid[newi][newj]==1){
                                st.insert(find(newid,parent));
                            }
                        }
                    }
                    int hehe = 0;
                    for(auto it:st){
                        hehe+=size[it];
                    }
                    count = max(hehe+1,count);
                }
            }
        }

        for(auto it:size){
            count = max(count,it);
        }

        return count;
    }
};