class MyHashSet {
public:
    int m;

    vector<list<int>>bucket;


    MyHashSet() {
        m = 15000;
        bucket = vector<list<int>>(m,list<int>{});
    }
    
    void add(int key) {
        int idx = key%m;
        auto itr = find(bucket[idx].begin(),bucket[idx].end(),key);

        if(itr==bucket[idx].end()){
            bucket[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = key%m;
        auto itr = find(bucket[idx].begin(),bucket[idx].end(),key);

        if(itr!=bucket[idx].end()){
            bucket[idx].erase(itr);
        }
    }
    
    bool contains(int key) {
        int idx = key%m;
        auto itr = find(bucket[idx].begin(),bucket[idx].end(),key);

        return itr!=bucket[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */