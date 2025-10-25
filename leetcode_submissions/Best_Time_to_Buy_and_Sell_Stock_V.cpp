class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = LLONG_MIN / 4;     
        vector<long long> free(k + 1, NEG), longPos(k + 1, NEG), shortPos(k + 1, NEG);
        free[0] = 0;  

        for (int price : prices) {
            auto prevFree = free;      
            auto prevLong = longPos;
            auto prevShort = shortPos;

            for (int t = 0; t <= k; ++t) {
               
                if (t < k && prevFree[t] != NEG) {
                    longPos[t] = max(longPos[t], prevFree[t] - price);   
                    shortPos[t] = max(shortPos[t], prevFree[t] + price);  
                }

                if (t > 0) {
                    if (prevLong[t - 1] != NEG)
                        free[t] = max(free[t], prevLong[t - 1] + price);  
                    if (prevShort[t - 1] != NEG)
                        free[t] = max(free[t], prevShort[t - 1] - price); 
                }
            }
        }
        return *max_element(free.begin(), free.end()); 
    }
};
