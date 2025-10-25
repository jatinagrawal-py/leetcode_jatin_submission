class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(0);
        for(int i = 0;i<boxes.size();i++){
            int ass = 0;
            for(int j = 0 ; j<boxes.size();j++){
                if(i==j){
                    continue;
                }
                if(boxes[j]=='1'){
                    if(j>i){
                        ass = ass + j - i;
                    }
                    else if(j<i){
                        ass = ass - j + i;
                    }
                    
                }
            }
            ans.push_back(ass);
        }
        return ans;
    }
};