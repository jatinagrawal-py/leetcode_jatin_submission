class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     
        // longest subarray with 2 distinct numbers?
        unordered_map<int,int>mpp;

        int i = 0;
        int j= 0;
        int len = 0;
        int n=fruits.size();

        while(j<n){
            mpp[fruits[j]]++;

            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }

            if(mpp.size()<=2){
                len = max(len,(j-i+1));
            }

            j++;
        }

        return len;
    }
};