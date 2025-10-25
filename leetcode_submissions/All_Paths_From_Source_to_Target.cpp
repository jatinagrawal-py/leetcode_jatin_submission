class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<vector<int>>& graph , int i , int n , vector<int>&temp , int prev){
        if(i==n-1){
            res.push_back(temp);
            return;
        }

        for(auto it:graph[i]){
            if(it==prev)continue;
            temp.push_back(it);
            dfs(graph,it,n,temp,i);
            temp.pop_back();
        }
        return;

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>temp = {};
        temp.push_back(0);
        dfs(graph,0,n,temp,-1);
        return res;
    }
};