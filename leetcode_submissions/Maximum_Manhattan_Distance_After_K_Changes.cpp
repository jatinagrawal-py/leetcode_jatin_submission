class Solution {
public:
    int maxDistance(string ss, int k) {
        int n = 0, s = 0, e = 0, w = 0;

        int maxi = INT_MIN;

        for(int i = 0;i<ss.size();i++){
            if(ss[i]=='E')e++;
            else if(ss[i]=='W')w++;
            else if(ss[i]=='N')n++;
            else if(ss[i]=='S')s++;
            int md = abs(w-e) + abs(n-s);
            int steps = i+1;
            int wasted = steps-md;
            int hehe = 0;

            if(steps!=md){
                hehe = min(2*k , wasted);
            }

            maxi = max(maxi , md + hehe);
        }

        return maxi;
    }
};