class Solution {
public:
    unordered_map<long long , int>mpp;
    int solve(string &s , int k , long long i , long long unique_char , bool canchange){
        if(i>=s.size())return 0;
        long long key = ((i<<27) | (unique_char<<1) | (canchange));
        if(mpp.find(key)!=mpp.end())return mpp[key];

        int idx = s[i]-'a';
        int newunique = unique_char | (1<<idx);
        int howmany = __builtin_popcount(newunique);

        int res = 0;
        
        if(howmany>k){
            res = 1 + solve(s,k,i+1,(1<<idx),canchange);
        }
        else{
           res = solve(s,k,i+1,newunique,canchange); 
        }

        if(canchange){
            for(int j = 0;j<26;j++){
                int newunique_set = unique_char | (1<<j);
                int howmany_set = __builtin_popcount(newunique_set);
                
                if(howmany_set>k){
                    res = max(res,1 + solve(s,k,i+1,(1<<j),false));
                }
                else{
                res = max(res,solve(s,k,i+1,newunique_set,false)); 
                }
            }
        }

        return mpp[key]= res;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        return (solve(s,k,0,0,true)+1);
    }
};