class Solution {
public:
    string findkbase(string num , int k){
        long long n = stoll(num);
        string res = "";
        while(n>0){
            res+= to_string(n%k);
            n/=k;
        }
        // reverse(begin(res),end(res));
        return res;
    }

    bool checkpal(string num){
        int i = 0;
        int j = num.size()-1;

        while(i<=j){
            if(num[i]!=num[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    long long kMirror(int k, int n) {
        int L = 1;
        long long sum = 0;

        while(n>0){
            int len_need = (L+1)/2;
            long long min_number = pow(10,len_need-1);
            long long max_number = pow(10,len_need) -1 ;

            for(long long i = min_number ; i<=max_number ;i++ ){
                string num = to_string(i);
                string reverse_num = num;
                reverse(begin(reverse_num),end(reverse_num));
                string pal = "";

                if(L%2==0){
                    pal = num + reverse_num;
                }
                else{
                    pal = num+ reverse_num.substr(1);
                }

                string k_mirror = findkbase(pal , k);

                if(checkpal(k_mirror)){
                    n--;
                    sum += stoll(pal);
                    if(n==0) return sum;
                }
            }
            L++;
        }

        return sum;
    }
};