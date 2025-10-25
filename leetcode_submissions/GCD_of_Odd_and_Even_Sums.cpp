class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = 0;
        int sumeven = 0;
        int j = 0;

        for(int i = 1;j<n;i+=2){
            sumodd+=i;
            j++;
        }
        j=0;
        for(int i = 0;j<n;i+=2){
            sumeven+=i;
            j++;
        }

        return __gcd(sumodd,sumeven);
    }
};