class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        if(d.size()==1){
            return 0;
        }
        for(int i = 0;i<d.size();i++){
            if(d[i][0]>d[i][1]){
                d[i][0] = d[i][0]^d[i][1];
                d[i][1] = d[i][0]^d[i][1];
                d[i][0] = d[i][0]^d[i][1];
            }
        }

        sort(d.begin(),d.end());
        int i =0;
        int j  =1;
        int count = 0;

        while(j<d.size()){
            if(d[i]!=d[j]){
                i = j;
                j++;
            }
            else{
                count+=(j-i);
                j++;
            }
        }
       

        return count;
    }
};