class Solution {
public:
    string change(string s , int a){
        string ans = "";
        for(int i = 0;i<s.size();i++){
            if(i%2==1){
                char newchar = ((s[i]-'0')+a)%10;
                ans.push_back(newchar+'0');
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
    string rotate(string &s , int b){
        string ans = s;
        int n = s.size();
        int split = n - b; 

        reverse(ans.begin(), ans.begin() + split); 
        reverse(ans.begin() + split, ans.end()); 
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string findLexSmallestString(string s, int a, int b) {
        //%10
        queue<string>pq;
        pq.push(s);
        unordered_set<string>st;
        string ans = s;

        while(!pq.empty()){
            string old = pq.front();
            pq.pop();
            ans = min(ans,old);
            string news1 = change(old,a);
            string news2 = rotate(old,b);
            if(st.count(news1)==0){pq.push(news1); st.insert(news1);}
            if(st.count(news2)==0){pq.push(news2); st.insert(news2);}
        }
        return ans;
    }
};