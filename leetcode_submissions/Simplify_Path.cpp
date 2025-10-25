class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        string dir;
        stringstream ss(path);

        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                continue;
            } else if (dir == "..") {
                if (!dq.empty()) dq.pop_back();
            } else {
                dq.push_back(dir);
            }
        }

        string result = "";
        while (!dq.empty()) {
            result += "/" + dq.front();
            dq.pop_front();
        }

        return result.empty() ? "/" : result;
    }
};
