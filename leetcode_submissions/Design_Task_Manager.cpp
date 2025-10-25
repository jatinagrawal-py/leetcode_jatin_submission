class TaskManager {
    // userid taskid priority
    // task->userid,priority
public:
    unordered_map<int, pair<int,int>> taskuser;
    set<pair<int, pair<int,int>>> st;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto it : tasks) {
            taskuser[it[1]] = {it[0], it[2]};
            st.insert({-it[2], {-it[1], it[0]}});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskuser[taskId] = {userId, priority};
        st.insert({-priority, {-taskId, userId}});
    }
    
    void edit(int taskId, int newPriority) {
        int prev   = taskuser[taskId].second;
        int previd = taskuser[taskId].first;
        taskuser[taskId].second = newPriority;
        st.erase({-prev, {-taskId, previd}});
        st.insert({-newPriority, {-taskId, previd}});
    }
    
    void rmv(int taskId) {
        int prev   = taskuser[taskId].second;
        int previd = taskuser[taskId].first;
        taskuser.erase(taskId);
        st.erase({-prev, {-taskId, previd}});
    }
    
    int execTop() {
        if (st.size() == 0) return -1;
        int taskId = -(begin(st)->second.first);
        int user   = begin(st)->second.second;
        int prev   = taskuser[taskId].second;
        int previd = taskuser[taskId].first;
        taskuser.erase(taskId);
        st.erase({-prev, {-taskId, previd}});
        return user;
    }
};
