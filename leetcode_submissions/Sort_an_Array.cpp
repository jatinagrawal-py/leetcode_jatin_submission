class Solution {
public:
    // int solve(vector<int>& nums , int l , int idx , int r){
    //     int i = idx+1;
    //     int j = r;
    //     int ele = nums[idx];
    //     while(i<=j){
    //         if(nums[i]>ele){
    //             swap(nums[i],nums[j]);
    //             j--;
    //         }
    //         else{
    //             i++;
    //         }
    //     }
    //     swap(nums[idx],nums[j]);
    //     return j;

    // }
    // void quicksort(vector<int>& nums , int l , int r){
    //     if(l>=r){
    //         return;
    //     }
    //     int pivot = l;
    //     int idx = solve(nums,l,pivot,r);
    //     quicksort(nums,l,idx-1);
    //     quicksort(nums,idx+1,r);
    //     return;
    // }
    void merge(vector<int>&nums , int l , int mid , int r){
        int i = l;
        int j = mid+1;
        vector<int>temp;
        while(i<=mid && j<=r){
            if(nums[i]>=nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        i = l;
        while(i<=r){
            nums[i] = temp[i-l];
            i++;
        }

    }

    void mergesort(vector<int>&nums,int l , int r){
        if(l>=r)return;
        int mid = l +(r-l)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        // quicksort(nums,0,nums.size()-1);
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};