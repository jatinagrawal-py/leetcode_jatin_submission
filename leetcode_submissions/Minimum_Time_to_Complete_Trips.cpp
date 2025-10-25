class Solution {
public:
    long long find(long long mid , vector<int>&time){
        long long sum = 0;
        for(auto it:time){
            sum+=(mid/it);
        }

        return sum;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int mini = *min_element(time.begin(),time.end());
        long long r =(long long) mini*totalTrips;
        long long l = 1;
        long long mid;
        while(l<r){
            mid = l + (r-l)/2;

            long long trips = find(mid , time);

            if(trips>=totalTrips){
                r = mid;
            }
            else if(trips<totalTrips){
                l = mid+1;
            }
        }

        return l;
    }
};