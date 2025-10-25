class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>c;
        
        for(int i = 0;i<A.size();i++){
            unordered_map<int,int>mpp;
            int count = 0;
            for(int j = 0;j<=i;j++){
                mpp[A[j]]++;
                mpp[B[j]]++;
            }
            for(auto it:mpp){
                if(it.second==2)count++;
            }
            c.push_back(count);
        }

        return c;
    }
};