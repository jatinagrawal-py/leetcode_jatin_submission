class ExamTracker {
public:
    vector<int> times;
    vector<long long> prefix; 

    ExamTracker() {}

    void record(int time, int score) {
        times.push_back(time);
        if (prefix.empty()) prefix.push_back(score);
        else prefix.push_back(prefix.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        int l = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int r = upper_bound(times.begin(), times.end(), endTime) - times.begin() - 1;
        if (l > r || r < 0) return 0;
        return prefix[r] - (l ? prefix[l - 1] : 0);
    }
};
