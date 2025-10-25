class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for(int i = 0;i<n;i++){
            capacity[i]-=rocks[i];
        }

        sort(capacity.begin(),capacity.end());
        int count = 0;
        for(auto it:capacity){
            if(it==0)count++;
            else if(it<=additionalRocks){
                count++;
                additionalRocks-=it;
            }
            else{
                break;
            }
        }


        return count;
    }
};