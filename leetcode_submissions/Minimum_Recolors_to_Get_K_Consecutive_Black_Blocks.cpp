class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int black = INT_MIN;

        int count=0;
        for(int i = 0;i<k;i++){
            if(blocks[i]=='B')count++;
        }
        black = max(black,count);

        for(int i = 1;i<=n-k;i++){
            if(blocks[i-1]=='B')count--;
            if(blocks[i+k-1]=='B')count++;
            black = max(black,count);
        }

        return k-black;

    }
};