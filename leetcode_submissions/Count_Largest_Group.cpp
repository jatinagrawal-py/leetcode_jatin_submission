class Solution {
public:
    int find(string dig){
        int sum = 0;
        for(auto it:dig){
            sum+=(it-'0');
        }

        return sum;
    }


    int countLargestGroup(int n) {

        unordered_map<int,vector<int>>mpp;

        for(int i  =1;i<=n;i++){
            string dig = to_string(i);
            int sum = find(dig);
            mpp[sum].push_back(i);
        }

        int maxi = INT_MIN;

        for(auto it:mpp){
            int si = static_cast<int>(it.second.size());
            maxi = max(maxi,si);
        }

        int count = 0;

        for(auto it:mpp){
            if(it.second.size()==maxi){
                count++;
            }
        }

        return count;

    }
};