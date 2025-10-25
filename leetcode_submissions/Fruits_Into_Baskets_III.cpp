class Solution {
public:
    void buildtree(int i , int l , int r , vector<int>&segment , vector<int>& baskets){
        if(l==r){
            segment[i] = baskets[l];
            return;
        }

        int mid = l + (r-l)/2;

        buildtree(2*i+1 , l,mid,segment , baskets);
        buildtree(2*i+2 , mid+1,r,segment , baskets);

        segment[i] = max(segment[2*i+1],segment[2*i+2]);

        return;
    }

    bool find(int i , int l , int r , int fruit , vector<int>&segment){
        if(fruit>segment[i])return false;

        if(l==r){
            segment[i] =-1;
            return true;
        }
        int mid = l + (r-l)/2;

        bool placed = false;

        if(segment[2*i+1]>=fruit){
            placed = find(2*i+1,l,mid , fruit , segment);
        }
        else{
            placed = find(2*i+2,mid+1,r , fruit , segment);
        }

        segment[i]  = max(segment[2*i+1],segment[2*i+2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<int>segment(4*n,-1);
        
        buildtree(0,0,n-1,segment  , baskets);
        int count = 0;
        for(auto it:fruits){
            if(find(0,0,n-1,it,segment)==false){
                count++;
            }
        }
        return count;
    }
};