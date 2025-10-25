class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // target-pos = kitne distance hai / uski speed = time it takes to reach the destination ??
        // 12-10/2 = 1
        // 12-8/4 = 1
        // 12-5/1 = 7
        //12-3/3 = 3
        // 12/1 = 12
        // jiski position age + uska time jyada ya toh equal piche walo se toh woh fleet banaega hi banaega 
        // curr pos se uske piche walo ka time ya toh kam ya equal hai toh woh fleet banaenge 

        // niche se start karo and check karte chalo kya niche koi hai jo kam hai ya toh equal hai? if yes then pop al those element and then count++; and push

        // 100/4 = 25
        // 98/2 = 49
        // 96/1 = 96

        // 4/3 = 1....
        // 2/2 = 1

        vector<pair<int,int>>arr;
        for(int i = 0;i<speed.size();i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());

        stack<double>st;

        for (int i = arr.size() - 1; i >= 0; i--) {
            double time = (double)(target - arr[i].first) / arr[i].second;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};