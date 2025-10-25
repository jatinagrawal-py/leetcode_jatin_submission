class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
         if (changed.size() % 2 == 1) {  // If odd, return empty
            return {};
        }
        
        vector<int> ans;
        unordered_map<int, int> freq;
        sort(changed.begin(), changed.end());  // Sorting ensures smaller elements come first

        for (int num : changed) {
            freq[num]++;  // Counting frequency of each element
        }

        for (int num : changed) {
            if (freq[num] == 0) {  // If already used, skip it
                continue;
            }

            if (freq[num * 2] == 0) {  // If doubled number is missing, return {}
                return {};
            }

            ans.push_back(num);
            freq[num]--;      // Reduce frequency of the original number
            freq[num * 2]--;  // Reduce frequency of the doubled number
        }

        return ans;
    }
};