class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // j-i % k
        unordered_map<int,int>mpp;
        for(int i = 0;i<energy.size();i++){
            if(mpp.find(i%k)==mpp.end()){
                mpp[i%k] = energy[i];
            }
            else{
                if(mpp[i%k]<0){
                    mpp[i%k] = 0;
                }
                mpp[i%k] += energy[i];
            }
        }
        int maxi = INT_MIN;
        for(auto it:mpp){
            maxi = max(maxi,it.second);
        }

        return maxi;
    }
};