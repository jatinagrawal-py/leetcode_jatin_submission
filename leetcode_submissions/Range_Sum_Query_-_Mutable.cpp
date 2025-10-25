class NumArray {
public:
    vector<int>arr;
    int N ;
    void buildtree(vector<int>& nums , int i, int l , int r){
        if(l == r){
            arr[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildtree(nums , 2*i+1 , l , mid);
        buildtree(nums , 2*i+2 , mid+1 , r);
        arr[i] = arr[2*i + 1] + arr[2*i + 2];
    }

    void arrupdate(int i , int val ,int idx , int l , int r ){
        int mid = l + (r-l)/2 ;
        if(l==r){
            arr[idx] = val;
            return;
        }
        if(i<= mid){
            arrupdate(i , val ,2*idx+1, l , mid);
            
        }
        else{
            arrupdate(i , val ,2*idx+2, mid+1 , r);
            
        }

        arr[idx] = arr[2*idx+1]+ arr[2*idx + 2];
    }

    int arrsum( int start , int end , int i , int l , int r){
        if(l>end || r<start){
            return 0;
        }
        if(l>=start && r<=end){
            return arr[i];
        }
        int mid = l + (r-l)/2 ;
        return arrsum(  start ,  end ,  2*i + 1 ,  l ,  mid) + arrsum(  start ,  end ,  2*i+2 ,  mid+1 ,  r);
    }

    NumArray(vector<int>& nums) {
        int n = nums.size();
        N = n;
        arr.resize(4*n);
        buildtree(nums , 0 , 0 , n-1);
    }
    
    void update(int index, int val) {
        arrupdate(index , val ,0, 0 , N-1);
    }
    
    int sumRange(int left, int right) {
        return arrsum( left , right , 0 , 0 , N-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */