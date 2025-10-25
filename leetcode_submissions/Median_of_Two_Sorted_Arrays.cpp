class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> v;

        for(auto num:nums1){
            v.push_back(num);
        }
        for(auto num:nums2){
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        int n = v.size();

        double median;
        if(n%2==0){
            median = (v[n/2]+v[(n/2)-1])/2.0;
        }
        else if(n%2==1){
            int total = v[n/2];
            median = total;
        }
        return median;
    }
};