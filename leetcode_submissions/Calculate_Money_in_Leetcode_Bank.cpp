class Solution {
public:
    int totalMoney(int n) {
        // jitne maonday= utne ruppe se wapis start karegA
        int count =0;
        int i = 1;
        while(n>=7){
            count+=(7*i+28-7);
            n-=7;
            i++;
        }
        int j = 0;
        while(n--){
            count+=(i+j);
            j++;
        }

        return count;

    }
};