class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        queue<pair<string,int>>pq;
        pq.push({"0000",0});
        unordered_set<string>st(deadends.begin(),deadends.end());
        unordered_set<string>vis;
        vis.insert("0000");
        if(st.find("0000")!=st.end()) return -1;
        while(!pq.empty()){
            string old = pq.front().first;
            int steps = pq.front().second;
            pq.pop();
            if(old==target){
                return steps;
            }
            for (int i = 0; i < 4; i++) {
                string up = old;
                string down = old;

                up[i] = (old[i] == '9') ? '0' : old[i] + 1;
                down[i] = (old[i] == '0') ? '9' : old[i] - 1;

                for (auto &next : {up, down}) {
                    if (!st.count(next) && !vis.count(next)) {
                        pq.push({next, steps + 1});
                        vis.insert(next);
                    }
                }
            }

        }
        return -1;
    }
};