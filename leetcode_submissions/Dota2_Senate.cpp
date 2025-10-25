class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0;
        int d = 0;
        int n = senate.size();

        for(auto it:senate){
            if(it=='R')r++;
            else{
                d++;
            }
        }

        int ischangedr = 0;
        int ischangedd = 0;

        int i = 0;
        while(r>0 && d>0){
            i = i%n;
            if(senate[i]=='R' && ischangedr<1){
                d--;
                ischangedd++;
            }
            else if(senate[i]=='D' && ischangedd<1){
                r--;
                ischangedr++;
            }
            else if(senate[i]=='R' && ischangedr>=1){
                senate[i]='-';
                ischangedr--;
            }
            else if(senate[i]=='D' && ischangedd>=1){
                senate[i]='-';
                ischangedd--;
            }
            i++;
        }

        if(r==0){
            return "Dire";
        }


        return "Radiant";
    }
};