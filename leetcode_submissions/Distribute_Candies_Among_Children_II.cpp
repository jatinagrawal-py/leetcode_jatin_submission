class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        int mini = max(0,n-2*limit);
        int maxi = min(n,limit);

        for(int i = mini;i<=maxi;i++){
            int N = n-i;

            int minii = max(0,N-limit);
            int maxii = min(N,limit);

            ways+=(maxii-minii+1);
        }

        return ways;
    }
};