class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        vector<int> ew(n);
        ew = indices;
        sort(ew.begin(),ew.end());
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                if(ew[i]==indices[j]){
                    char temp;
                    temp = s[i];
                    s[i]=s[j];
                    s[j]=temp;
                    int temp1;
                    temp1 = indices[i];
                    indices[i]=indices[j];
                    indices[j]=temp1;
                }
        }
        }
        return s;
    }
};