class Solution {
public:
    int solve( int exchange , int khali ){

        if(khali<exchange)return 0;
        int newbhari = 0;
        newbhari = khali/exchange;
        int rem = khali%exchange;
        return newbhari+solve(exchange,newbhari+rem);
    }
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+ solve(numExchange,numBottles);
    }
};