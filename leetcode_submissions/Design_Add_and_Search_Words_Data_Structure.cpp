class WordDictionary {
public:
    struct Trie{
        Trie* children[26]={NULL};
        bool flag = false;
    };

    Trie* root;

    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* temp = root;
        for(auto it:word){
            if(temp->children[it-'a']==NULL){
                Trie* naya = new Trie();
                temp->children[it-'a'] = naya;
            }
            temp = temp->children[it-'a'];
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        Trie* temp = root;
        return dfs(word,temp,0);
    }

    bool dfs(string &word , Trie* temp , int i){
        if(temp==NULL)return false;
        if(i==word.size()){
            return temp->flag;
        }

        if(word[i]!='.'){
            return dfs(word,temp->children[word[i]-'a'],i+1);
        }

        for(int j = 0;j<26;j++){
            if(dfs(word,temp->children[j],i+1)){
                return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */