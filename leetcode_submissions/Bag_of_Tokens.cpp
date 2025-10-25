class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // power jaegi toh score bhadega
        sort(tokens.begin(),tokens.end());
        int maxi = 0;
        int i = 0;
        int j = tokens.size()-1;
        int score = 0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                maxi = max(score,maxi);
                power-=tokens[i];
                i++;
            }
            else{
                if(score>0)
                {power+=tokens[j];
                j--;
                score--;}
                else{
                    return maxi;
                }
            }
        }


        return maxi;
    }
};