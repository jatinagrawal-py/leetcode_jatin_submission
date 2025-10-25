class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
            std::unordered_map<int, std::vector<int>> sizeToPeople;
    std::vector<std::vector<int>> result;

    for (int i = 0; i < groupSizes.size(); ++i) {
        int size = groupSizes[i];
        sizeToPeople[size].push_back(i);

        // If we have enough people to form a complete group, add it to result
        if (sizeToPeople[size].size() == size) {
            result.push_back(sizeToPeople[size]);
            sizeToPeople[size].clear(); // Reset the list for this group size
        }
    }

    return result;
    }
};