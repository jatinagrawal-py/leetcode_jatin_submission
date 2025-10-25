class Solution {
public:
    int maximum69Number (int num) {
        string hehe = to_string(num);
        for(auto &it :hehe){
            if(it=='6'){
                it = '9';
                break;
            }
        }

        return stoi(hehe);
    }
};