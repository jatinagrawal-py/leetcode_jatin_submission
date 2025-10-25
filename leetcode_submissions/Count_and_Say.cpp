class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        // - kitni bar likha hua hai -  ele 
        string hehe = countAndSay(n-1);

        string temp = "";

        int count = 1;
        char ele = hehe[0];
        for(int i = 1;i<hehe.size();i++){
            if(ele==hehe[i]){
                count++;
            }
            else{
                temp+=(to_string(count));
                temp+=ele;
                ele = hehe[i];
                count = 1;
            }
        }
        
        temp+=(to_string(count));
        temp+=ele;

        return temp;
    }
};