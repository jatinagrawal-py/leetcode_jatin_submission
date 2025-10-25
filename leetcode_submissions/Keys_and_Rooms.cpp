class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>pq;
        int n = rooms.size();
        pq.push(0);
        vector<bool>vis(n,false);
        vis[0] = true;

        while(!pq.empty()){
            int u = pq.front();
            pq.pop();
            for(auto it:rooms[u]){
                if(vis[it]==false){
                    pq.push(it);
                    vis[it]=true;
                }
            }
        }

        for(auto it:vis){
            if(it==false)return false;
        }

        return true;
    }
};