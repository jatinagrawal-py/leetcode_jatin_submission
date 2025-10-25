class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int>mpp;
        int i = 0;
        int j = 0;
        int n = arrivals.size();
        int count = 0;
        while(j<n){
            while(j-i+1>w){
                mpp[arrivals[i]]--;
                if(mpp[arrivals[i]]<=0){
                    mpp.erase(arrivals[i]);
                }
                i++;
            }
            if(mpp[arrivals[j]]>=m){
                arrivals[j]=0;
                count++;  
            }
            else{
                mpp[arrivals[j]]++;
            }
            j++;
        }

        return count;
    }
};