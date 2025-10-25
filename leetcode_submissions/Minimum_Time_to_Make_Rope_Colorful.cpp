class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        int n = colors.size();
        int i = 0;
        int j = 1;
        int time  =0;
        if(n==1){
            return time;
        }
        int prev = nt[0];
        for(int i = 1 ;i<n;i++){
            if(colors[i]==colors[i-1]){
                time+=min(nt[i],prev);
                prev = max(nt[i],prev);
            }
            else{
                prev=nt[i];
            }
        }


        return time;
    }
};