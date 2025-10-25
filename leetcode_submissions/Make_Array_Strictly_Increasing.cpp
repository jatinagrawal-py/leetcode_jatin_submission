class Solution {
public:
    map<pair<int,int>,int>mpp;
    int solve(vector<int>& arr1, vector<int>& arr2 , int i , int prev){
        if(i>=arr1.size())return 0;

        if(mpp.find({i,prev})!=mpp.end()){
            return mpp[{i,prev}];
        }

        int nottake = 1e9;

        if( prev<arr1[i]){
            nottake = solve(arr1,arr2,i+1,arr1[i]);
        }

        auto idx = upper_bound(arr2.begin(),arr2.end(),prev) ;
        int take = 1e9;
        if(idx!=arr2.end()){
            int j = idx - arr2.begin();
            int temp = arr1[i];
            arr1[i] = arr2[j];
            take = 1 + solve(arr1,arr2,i+1,arr1[i]);
            arr1[i] = temp;
        }
        
        return mpp[{i,prev}]= min(take,nottake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int ans =  solve(arr1,arr2,0,-1);
        return ans >= 1e9 ? -1 : ans;
    }
};