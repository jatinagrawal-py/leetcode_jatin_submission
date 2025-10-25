class Solution {
public:
    int minMaxDifference(int num) {
        string maxi = to_string(num);
        string mini = to_string(num);
        char changedmaxi;
        char changedmini;
        for(int i = 0;i<maxi.size();i++){
            if(maxi[i]-'0'!=9){
                changedmaxi = maxi[i];
                break;
            }
        }

        for(auto &it:maxi){
            if(it==changedmaxi){
                it = '9';
            }
        }

        for(int i = 0;i<mini.size();i++){
            if(mini[i]-'0'!=0){
                changedmini = mini[i];
                break;
            }
        }

        for(auto &it:mini){
            if(it==changedmini){
                it = '0';
            }
        }


        return stoi(maxi)-stoi(mini);
    }
};