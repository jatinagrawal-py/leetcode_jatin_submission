class Solution {
public:
    long long calculateScore(vector<string>& in, vector<int>& values) {
        unordered_set<int>st;

        int n = values.size();
        long long score = 0;
        int i =0;

        while(i>=0 && i<n){
            if(st.find(i)!=st.end()){
                return score;
            }
            if(in[i]=="add"){
                score+=(long long)values[i];
                st.insert(i);
                i++;
            }
            else{
                st.insert(i);
                i+=values[i];
            }
        }


        return score;
        
    }
};