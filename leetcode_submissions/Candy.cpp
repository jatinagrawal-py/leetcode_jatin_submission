class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>l(n,1);
        vector<int>r(n,1);

        for(int i = 1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                l[i]=1+l[i-1];
            }
        }

        for(int i = n-2;i>=0;i--){
            if(ratings[i+1]<ratings[i]){
                r[i]=1+r[i+1];
            }
        }

        int count = 0;
        for(int i = 0;i<n;i++){
            count+=max(r[i],l[i]);
        }

        return count;
    }
};