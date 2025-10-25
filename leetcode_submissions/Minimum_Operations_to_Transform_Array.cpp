class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long count = 1;
        int mini = abs(nums1[0]-nums2[n]);
        int ele = nums1[0];
        if(mini>abs(nums2[0]-nums2[n])){
            ele = nums2[0];
            mini=(int)abs(nums2[0]-nums2[n]);
        }
        for(int i = 1;i<n;i++){
            if(mini>abs(nums1[i]-nums2[n])){
                ele = nums1[i];
                mini=(int)abs(nums1[i]-nums2[n]);
            }
            if(mini>abs(nums2[i]-nums2[n])){
                ele = nums2[i];
                mini=(int)abs(nums2[i]-nums2[n]);
            }
        }
        bool shouldwe = true;
        for(int i = 0;i<n;i++){
            if((nums1[i]>=nums2[n] && nums2[i]<=nums2[n]) || (nums1[i]<=nums2[n] && nums2[i]>=nums2[n])){
                shouldwe = false;
            }
            count+=(abs(nums1[i]-nums2[i]));
        }
        if(shouldwe){
            count+=mini;
        }

        return count;
    }
};