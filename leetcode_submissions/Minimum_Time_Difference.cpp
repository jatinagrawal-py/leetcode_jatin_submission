#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int findMinDifference(std::vector<std::string>& time) {
        int n = time.size();
        std::vector<int> minutes;
        
        // Convert each time string to minutes since midnight
        for (int i = 0; i < n; i++) {
            std::string h1 = time[i];
            int min1 = 60 * std::stoi(h1.substr(0, 2)) + std::stoi(h1.substr(3, 2));  // Convert "HH:MM" to total minutes
            minutes.push_back(min1);
        }
        
        // Sort the minutes to find the minimum difference between consecutive times
        std::sort(minutes.begin(), minutes.end());
        
        int mi = 1440;  // Maximum possible difference is 24 hours (1440 minutes)
        
        // Find the minimum difference between consecutive times in sorted order
        for (int i = 1; i < n; i++) {
            mi = std::min(mi, minutes[i] - minutes[i - 1]);
        }
        
        // Handle the wrap-around case (time difference over midnight)
        mi = std::min(mi, 1440 - (minutes[n - 1] - minutes[0]));  // Difference between the first and last time
        
        return mi;
    }
};
