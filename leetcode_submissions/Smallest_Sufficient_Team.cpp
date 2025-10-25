class Solution {
public:
    vector<int>ans;
    
    void solve(vector<string>& req_skills, vector<int>& people_skill , int i , vector<int>&temp,unordered_map<string,int>&mpp,int res){
        
        if(res==((1<<req_skills.size())-1)){
            if(ans.size()>temp.size()){
                ans = temp;
            }
            return;
        }
        if(i>=people_skill.size())return;

        if(temp.size()>=ans.size())return;

        solve(req_skills,people_skill,i+1,temp,mpp,res);


        if((res|people_skill[i])==res)return;

        temp.push_back(i);
        solve(req_skills,people_skill,i+1,temp,mpp,(res|people_skill[i]));
        temp.pop_back();

        return;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int>mpp;

        for(int i = 0;i<req_skills.size();i++){
            mpp[req_skills[i]]= i;
        }

        ans.resize(req_skills.size() + 1);

        vector<int>temp;
        vector<int>people_skill;

        for(auto it:people){
            int skill_bit = 0;
            for(auto v:it){
                int idx = mpp[v];
                skill_bit = (skill_bit|(1<<idx));
            }
            people_skill.push_back(skill_bit);
        }

        solve(req_skills,people_skill,0,temp,mpp,0);

        return ans;
    }
};