class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;

        int i = 0;
        int j = 0;
        int countf = 0;
        while(j<s.size()){
            if(s[j]=='F')countf++;

            while(countf>k){
                if(s[i]=='F')countf--;
                i++;
            }

            if(countf<=k){
                maxi1 = max(maxi1,(j-i+1));
            }
            j++;
        }
        i=0;j=0;
        int countt = 0;
        while(j<s.size()){
            if(s[j]=='T')countt++;

            while(countt>k){
                if(s[i]=='T')countt--;
                i++;
            }

            if(countt<=k){
                maxi2 = max(maxi2,(j-i+1));
            }
            j++;
        }

        return max(maxi1,maxi2);
    }
};