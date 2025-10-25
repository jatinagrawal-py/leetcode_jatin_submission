class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st(brokenLetters.begin(),brokenLetters.end());
        int count = 0;
        string hehe = "";
        bool cantype = true;
        for(auto it:text){
            if(it==' '){
                if(cantype){
                    count++;
                }
                cantype = true;
                hehe = "";
            }
            else{
                hehe+=it;
                if(st.count(it)){
                    cantype = false;
                }
            }
        }
       
        if(cantype){
            count++;
        }
        return count;
    }
};