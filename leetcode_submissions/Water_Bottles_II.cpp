class Solution {
public:
    int solve(int empty, int exRate) {
        if (empty < exRate) return 0;

        empty -= exRate;  
        int newFull = 1;   
        int newEmpty = empty + newFull; 

        return 1 + solve(newEmpty, exRate + 1);
    }

    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles + solve(numBottles, numExchange);
    }
};
