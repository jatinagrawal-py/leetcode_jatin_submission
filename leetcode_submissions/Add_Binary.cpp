class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;

        while(i >= 0 && j >= 0){
            if(a[i]=='1' && b[j]=='1'){
                if(carry==1){
                    ans = '1'+ans;
                    carry=1;  // sum = 1+1+1=3 -> 3%2=1, carry=1
                }
                else{
                    ans = '0'+ans;
                    carry = 1; // sum=1+1=2 -> 2%2=0, carry=1
                } 
            }
            else if(a[i]=='1' || b[j]=='1'){
                if(carry==1){
                    ans = '0'+ans; // sum = 1+carry=2 -> 2%2=0
                    carry=1;       // carry remains 1
                }
                else{
                    ans = '1'+ans; // sum = 1+carry=1 -> 1%2=1
                    carry = 0;
                } 
            }
            else{ // both 0
                if(carry==1){
                    ans = '1'+ans;
                    carry=0;
                }
                else{
                    ans = '0'+ans;
                    carry = 0;
                } 
            }
            i--;
            j--;
        }

        // remaining digits in a
        while(i >= 0){
            if(a[i]=='1'){
                if(carry==1){
                    ans = '0'+ans; // 1+1=2 -> 0
                    carry=1;
                }
                else{
                    ans = '1'+ans;
                    carry = 0;
                }
            }
            else{ // a[i]=='0'
                if(carry==1){
                    ans = '1'+ans;
                    carry=0;
                }
                else{
                    ans = '0'+ans;
                    carry = 0;
                }
            }
            i--;
        }

        // remaining digits in b
        while(j >= 0){
            if(b[j]=='1'){   // ❌ fixed from a[j] to b[j]
                if(carry==1){
                    ans = '0'+ans;
                    carry=1;
                }
                else{
                    ans = '1'+ans;
                    carry = 0;
                }
            }
            else{
                if(carry==1){
                    ans = '1'+ans;
                    carry=0;
                }
                else{
                    ans = '0'+ans;
                    carry = 0;
                }
            }
            j--;
        }

        // if carry is left
        if(carry==1){
            ans = '1'+ans;
        }

        return ans;
    }
};
