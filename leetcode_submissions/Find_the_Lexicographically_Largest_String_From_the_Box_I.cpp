class Solution {
public:
    string answerString(string word, int numFriends) {
        // 1 * n-1 -> minimum 
        // 1 ko tu word.len() - n-1   itna de sakta hai usko ab itne len ka dhundh le maximum
        // acbd   -> 3 

        if(numFriends==1)return word;

        char maxi = 'a';
        
        for(int i = 0;i<word.size();i++){
            if(maxi<word[i]){
                maxi = word[i];
            }
        }


        vector<int>index;
        for(int i = 0;i<word.size();i++){
            if(word[i]==maxi)index.push_back(i);
        }

        string hehe = "" ;

        for(auto it:index){
            int si = word.size() - (numFriends - 1);
            int j = it;
            string temp = "";
            while(si-- && j<word.size()){
                temp+=word[j];
                j++;
            }
            hehe = max(hehe,temp);
        }
        

        return hehe;
        
    }
};