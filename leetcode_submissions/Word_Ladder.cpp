class Solution {
public:
    vector<char>alpha = {'a','b' , 'c','d','e' , 'f','g','h' , 'i','j','k' , 'l','m','n' , 'o','p','q' , 'r','s','t' , 'u','v','w' , 'x','y','z'};

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>pq;
        pq.push(beginWord);

        unordered_set<string>st(wordList.begin(),wordList.end());
        int level = 1;
        int n = beginWord.size();
        while(!pq.empty()){
            int x = pq.size();
        
        while(x--){
            for(auto it:alpha){
                for(int i = 0;i<n;i++){
                    if(pq.front()==endWord)return level;
                    string temp  = pq.front();
                    temp[i] = it;
                    if(st.find(temp)!=st.end()){
                        pq.push(temp);
                        st.erase(temp);
                    }
                }
            }
            pq.pop();
        }
            level++; 
        }
        return 0;
    }
};