class Solution {
public:
    bool isValid(int num) {
        return num % 2 == 0 && num >= 100 && num <= 999;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> uniqueNumbers;
        int n = digits.size();

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    if(i != j && j != k && i != k){
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if(isValid(num)){
                            uniqueNumbers.insert(num);
                        }
                    }
                }
            }
        }

        return vector<int>(uniqueNumbers.begin(), uniqueNumbers.end());
    }
};
