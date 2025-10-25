class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        // 0->n tak phele toh direct assign kardo prev se lekin usmai max dekh lena kab free ho raha uske hisab se <- upar se
        // phir kya karna hai backtrack karna hai n->0 ki taraf synchronize karke
        int m = mana.size();
        int n = skill.size();
        vector<long long >prev(n,0);
        prev[0] = mana[0]*skill[0];
        for(int i = 1;i<n;i++){
            prev[i] = prev[i-1] + mana[0]*skill[i];
        }
        for(int i = 1;i<m;i++){ // mana wala hai ye bhosdi
            vector<long long>finish(n,0);
            finish[0] = prev[0]+mana[i]*skill[0];
            for(int j = 1;j<n;j++){
                finish[j] = max(finish[j-1],prev[j]) + mana[i]*skill[j];
            }
            for(int j = n-2;j>=0;j--){
                finish[j] = finish[j+1]-mana[i]*skill[j+1];
            }

            prev = finish;
        }

        return prev[n-1];
    }
};