class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int>mpp;

        for(auto it:ans){
            mpp[it]++;
        }   

        int rab = 0;

        for(auto it:mpp){
            int size = it.first + 1;
            int num = it.second;
            rab += ((num + size - 1) / size) * size;
        }

        return rab;
    }
};