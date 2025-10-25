class RandomizedSet {
public:
    unordered_map<int,int>mpp;
    vector<int>arr;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mpp.find(val)!=mpp.end())return false;

        arr.push_back(val);
        int index = arr.size()-1;
        mpp[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val)!=mpp.end()){
            int index = mpp[val];
            int lastele = arr.back();
            arr[index]=lastele;
            mpp[lastele]=index;
            mpp.erase(val);
            arr.pop_back();
            return true;
        }


        return false;
    }
    
    int getRandom() {
        int index = rand()%arr.size();
        return arr[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */