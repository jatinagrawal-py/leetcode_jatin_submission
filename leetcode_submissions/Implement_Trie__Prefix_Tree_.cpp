class Trie {
public:

    struct trienode{
        trienode* children[26] = {NULL};
        bool last = false;
    };

    trienode * root;

    Trie() {
        root = new trienode();
    }
    
    void insert(string word) {
        trienode * node = root;
        for(auto it:word){
            int i = it-'a';
            if(node->children[i]==NULL){
                trienode * newnode = new trienode();
                node->children[i] = newnode; 
            }
            node = node->children[i]; 
        }
        node->last = true;
    }
    
    bool search(string word) {
        trienode * node = root;
        
        for(auto it:word){
            int i = it-'a';
            if(node->children[i]==NULL)return false;
            node = node->children[i];
        }

        return node->last;
    }
    
    bool startsWith(string word) {
        trienode * node = root;
        
        for(auto it:word){
            int i = it-'a';
            if(node->children[i]==NULL)return false;
            node = node->children[i];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */