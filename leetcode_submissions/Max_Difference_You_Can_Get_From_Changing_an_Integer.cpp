class Solution {
public:
    int maxDiff(int num) {
        // a bada b chota 
        // sabse phela 9 hona chaiye 
        // sabse phela 0
        // 9988   
        
      
        string hehe1 = to_string(num);

        char x = 'a';
        for(auto it:hehe1){
            if(it!='9'){
                x = it;
                break;
            }
        }
        if(x!='a'){
            for(auto &it:hehe1){
                if(it==x){
                    it='9';
                }
            }
        }
        
        string hehe2 = to_string(num);
        char y = 'a';
        if(hehe2[0]!='1'){
            for(auto it:hehe2){
                if(it!='1'){
                    y = it;
                    break;
                }
            }
            if(y!='a'){
                for(auto &it:hehe2){
                    if(it==y){
                        it='1';
                    }
                }
            }
        }
        else{
            for(auto it:hehe2){
                if(it!='1' && it!='0'){
                    y = it;
                    break;
                }
            }
            if(y!='a'){
                for(auto &it:hehe2){
                    if(it==y){
                        it='0';
                    }
                }
            }
        }
        
        return stoi(hehe1) - stoi(hehe2);
    }
};