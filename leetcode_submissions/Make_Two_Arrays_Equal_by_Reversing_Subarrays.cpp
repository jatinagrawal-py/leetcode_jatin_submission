class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        bool ans ;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        if(arr==target){
            ans = true;
        }
        else{
            ans = false;
        }
        return ans;
    }
};