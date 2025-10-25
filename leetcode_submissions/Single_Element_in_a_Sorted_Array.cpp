class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n==1){
            return nums[0];
        }

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mid == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    l = mid + 2;
                } else {
                    return nums[mid];
                }
            }
            else if (mid == n - 1) {
                if (nums[mid] == nums[mid - 1]) {
                    r = mid - 2;
                } else {
                    return nums[mid];
                }
            }
            else {
                if (nums[mid] == nums[mid + 1]) {
                    if ((r - mid) % 2 == 0) {
                        l = mid + 2;
                    } else {
                        r = mid - 1;
                    }
                }
                else if (nums[mid] == nums[mid - 1]) {
                    if ((mid - l) % 2 == 0) {
                        r = mid - 2;
                    } else {
                        l = mid + 1;
                    }
                }
                else {
                    return nums[mid];
                }
            }
        }

        return -1;
    }
};
