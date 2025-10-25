class Solution {
public:
    
    void bfs(int u , unordered_map<int,vector<int>>&adj  , int n , vector<int>&hehe){

        queue<int>pq;
        pq.push(u);
        hehe[u]=0;

        while(!pq.empty()){
            int v = pq.front();
            pq.pop();

            for(auto it:adj[v]){
                if(hehe[it]==-1){
                    hehe[it] = 1 - hehe[v];
                    pq.push(it);
                }
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1;
        unordered_map<int,vector<int>>adj2;
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        vector<int>ans(n);
        
        vector<int>hehe1(n,-1);
        vector<int>hehe2(m,-1);
        bfs(0,adj1,n,hehe1);
        bfs(0,adj2,m,hehe2);

        int countzero1 = 0;
        int countone1 = 0;
        for(auto it:hehe1){
            if(it==0)countzero1++;
            else countone1++;
        } 

        int countzero2 = 0;
        int countone2 = 0;
        for(auto it:hehe2){
            if(it==0)countzero2++;
            else countone2++;
        } 
        int maxi = max(countzero2,countone2);
        for(int i = 0;i<n;i++){
            if(hehe1[i]==0){
                ans[i] = countzero1 + maxi;
            }
            else{
                ans[i] = countone1 + maxi;
            }
        }

        return ans;
    }
};