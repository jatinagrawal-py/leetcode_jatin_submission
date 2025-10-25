class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;

        for(auto it : s){
            mpp[it]++;
        }

        priority_queue<pair<int,char>>q;

        for(auto it : mpp){
            q.push({it.second,it.first});
        }

        string result = "";

        while(!q.empty()){
            for(int i = 0;i<q.top().first;i++){
                result+=q.top().second;
            }  
            q.pop();
        }

        return result;
    }
};