class MyHashMap {
public:
    vector<vector<pair<int,int>>>bucket;
    int m ;
    MyHashMap() {
        m = 15000;
        bucket = vector<vector<pair<int,int>>>(m);
    }
    
    void put(int key, int value) { 
        int idx = key%m;
        
        for(auto &it:bucket[idx]){
            if(it.first==key){
                it.second = value;
                return;
            }
        }
        bucket[idx].push_back({key,value});
        
    }
    
    int get(int key) {
        int idx = key%m;
        
        for(auto &it:bucket[idx]){
            if(it.first==key){
                
                return it.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int idx = key%m;
        
        int i = -1;
        for(auto &it:bucket[idx]){
            i++;
            if(it.first==key){
                bucket[idx].erase(bucket[idx].begin()+i);
                return;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */