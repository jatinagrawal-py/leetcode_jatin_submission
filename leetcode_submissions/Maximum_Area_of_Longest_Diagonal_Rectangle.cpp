class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = INT_MIN;
        int diagonal = INT_MIN;
        for(auto it:dimensions){
            int a = it[0];
            int b = it[1];
            if((a*a + b*b )>diagonal){
                area = a*b; 
                diagonal = a*a+b*b;
            }
            if((a*a + b*b )==diagonal){
                area = max(area,a*b);
            }
        }
        return area;
    }
};