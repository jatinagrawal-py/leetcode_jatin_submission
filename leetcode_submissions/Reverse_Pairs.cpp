class Solution {
public:
    int res = 0;

    void find(int low , int mid , int high , vector<int>& nums){
        int i = low;
        int j = mid + 1;

        while(i <= mid && j <= high){
            if((long long)nums[i] > 2LL * nums[j]) {
                res += (mid - i + 1);
                j++;
            } else {
                i++;
            }
        }
    }

    void merge(int low , int mid , int high , vector<int>& nums){
        int left = low;
        int right = mid + 1;
        vector<int> temp;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid){
            temp.push_back(nums[left++]);
        }

        while(right <= high){
            temp.push_back(nums[right++]);
        }

        for(int i = 0; i < temp.size(); ++i){
            nums[low + i] = temp[i];
        }
    }

    void mergesort(int low , int high , vector<int>& nums){
        if(low >= high) return;

        int mid = low + (high - low) / 2;

        mergesort(low , mid , nums);
        mergesort(mid + 1 , high , nums);

        find(low, mid, high, nums);  
        merge(low, mid, high, nums); 
    }

    int reversePairs(vector<int>& nums) {
        mergesort(0, nums.size() - 1, nums);
        return res;
    }
};
