class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int topfront = tops[0];
        int bottomfront = bottoms[0];
        int n = tops.size();

        int counttf = 0;
        int countbf = 0;

        for(int i =0;i<n;i++){
            if(tops[i]==topfront || bottoms[i]==topfront){
                counttf++;
            }
            if(tops[i]==bottomfront || bottoms[i]==bottomfront){
                countbf++;
            }
        }

        if(countbf<n && counttf<n){
            return -1;
        }

        int hehe;
        if(countbf==n){
            hehe = bottomfront;
        }
        else{
            hehe = topfront;
        }
        
        int upar = 0;
        int niche = 0;
        for(int i = 0;i<n;i++){
            if(tops[i]==hehe){
                upar++;
            }
            if(bottoms[i]==hehe){
                niche++;
            }
        }
        
        // upar -> 4 

        // if(upar>=(n/2)){
        //     return n-upar;
        // }

        return min(n-upar,n-niche);

        
    }
};