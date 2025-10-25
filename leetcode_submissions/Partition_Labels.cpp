class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mpp;
        
        // Step 1: Store the first and last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            if (mpp.find(s[i]) == mpp.end()) {
                mpp[s[i]] = {i, i};
            } else {
                mpp[s[i]].second = i;
            }
        }
        
        // Step 2: Store the intervals
        vector<pair<int, int>> intervals;
        for (auto it : mpp) {
            intervals.push_back(it.second);
        }
        
        // Step 3: Sort intervals based on start index
        sort(intervals.begin(), intervals.end());
        
        // Step 4: Merge overlapping intervals and find partition lengths
        vector<int> res;
        int start = intervals[0].first;
        int end = intervals[0].second;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > end) { // No overlap
                res.push_back(end - start + 1);
                start = intervals[i].first;
                end = intervals[i].second;
            } else { // Overlapping intervals
                end = max(end, intervals[i].second);
            }
        }
        
        // Add the last merged interval
        res.push_back(end - start + 1);
        
        return res;
    }
};
