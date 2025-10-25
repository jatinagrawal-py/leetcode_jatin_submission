class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i=0;i<n;i++){
            reverse(image[i].begin(),image[i].end());
            for(int j=0;j<n;j++){
                if(image[i][0]==1){
                    image[i].push_back(0);
                    image[i].erase(image[i].begin());
                }
                else if(image[i][0]==0){
                    image[i].push_back(1);
                    image[i].erase(image[i].begin());
                }
            }
        }
        return image;
    }
};