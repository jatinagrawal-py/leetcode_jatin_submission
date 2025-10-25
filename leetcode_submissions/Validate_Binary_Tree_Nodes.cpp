class Solution {
public:
    int find(int x , vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unionn(int x , int y , vector<int>& parent){
        int xp = find(x, parent);
        int yp = find(y, parent);
        if(xp != yp){
            parent[yp] = xp;
        }
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n);
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++) parent[i] = i;

        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                if(++indegree[leftChild[i]] > 1) return false;
                if(find(i, parent) == find(leftChild[i], parent)) return false;
                unionn(i, leftChild[i], parent);
            }
            if(rightChild[i] != -1){
                if(++indegree[rightChild[i]] > 1) return false;
                if(find(i, parent) == find(rightChild[i], parent)) return false;
                unionn(i, rightChild[i], parent);
            }
        }

        int rootCount = 0;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) rootCount++;
        }

        return rootCount == 1;
    }
};
