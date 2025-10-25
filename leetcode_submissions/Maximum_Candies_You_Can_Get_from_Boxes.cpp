class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // boxes without keys + STATSUS FALSE-> set 
        // queue jinki keys hai + status true hai
        
        // found boxes but not opened or status = 0 -> 1 set mai
        // found boxes with status = ture; -> queue

        unordered_set<int>avalbox;
        queue<int>pq;
        int n = status.size();

        for(auto it:initialBoxes){
            if(status[it]){
                pq.push(it);
            }
            else{
                avalbox.insert(it);
            }   
        }
        int ans = 0;
        while(!pq.empty()){
            int u = pq.front();
            pq.pop();
            ans+=candies[u];
            auto key = keys[u];
            auto box = containedBoxes[u];

            for(auto &hehe:key){
                status[hehe]=1;
            }

            for(auto hehe:box){
               avalbox.insert(hehe);
            }

            vector<int> to_remove;

            for (int hehe : avalbox) {
                if (status[hehe]) {
                    pq.push(hehe);
                    to_remove.push_back(hehe);
                }
            }

            for (int x : to_remove) {
                avalbox.erase(x);
            }

            
        }

        return ans;

    }
};