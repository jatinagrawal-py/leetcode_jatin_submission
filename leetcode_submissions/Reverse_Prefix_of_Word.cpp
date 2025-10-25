class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int k=-1;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                k=i;
                break;
            }
        }
        if(k!=-1 && k!=0){
            for(int i=0;i<(k/2)+1;i++){
            char temp = word[i];
            word[i]= word[k-i];
            word[k-i]=temp;
        }
        }
        return word;
    }
};