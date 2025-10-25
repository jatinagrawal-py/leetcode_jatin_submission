class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int it : asteroids) {
            bool destroyed = false;

            while (!ans.empty() && ans.back() > 0 && it < 0) {
                if (ans.back() < -it) {
                    ans.pop_back(); 
                } else if (ans.back() == -it) {
                    ans.pop_back(); 
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; 
                    break;
                }
            }

            if (!destroyed) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};
