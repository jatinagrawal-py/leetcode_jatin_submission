class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(),meetings.end());

        
        
        int end = 0;
        int count = 0;

        for(auto meet : meetings){
            if(meet[0]>end){
                count+=meet[0]- end - 1;
            }
            end = max(end , meet[1]);
        }

        if(end<days){
            count+=days-end;
        }

        return count;
    }
};