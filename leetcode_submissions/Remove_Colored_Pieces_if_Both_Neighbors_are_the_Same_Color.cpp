class Solution {
public:
    bool winnerOfGame(string colors) {
        // returbn true if alice the bhadwa wins
        int n = colors.size();

        if(n<3)return false;

        int a = 0;
        int b = 0;

        for(int i = 1;i<n-1;i++){
            if(colors[i-1]=='A' && colors[i]=='A' && colors[i+1]=='A'){
                a++;
            
            }
            else if(colors[i-1]=='B' && colors[i]=='B' && colors[i+1]=='B'){
                b++;
            
            }
        }

        bool flag = true;

        while(a>0 && b>0){
            if(flag){
                a--;
                flag = false;
            }
            else{
                flag = true;
                b--;
            }
        }

        if(a==0)return false;

        return true;

    }
};