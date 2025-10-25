class SmallestInfiniteSet {
public:
    set<int>st;
    int cursmall;
    SmallestInfiniteSet() {
        
       cursmall = 1;
    }
    
    int popSmallest() {
        if(!st.empty()){
            int a = *st.begin();
            st.erase(st.begin());
            return a;
        }

        int a = cursmall;
        cursmall++;
        return a;
    }
    
    void addBack(int num) {
        if(num>=cursmall){
            return;
        }

        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */