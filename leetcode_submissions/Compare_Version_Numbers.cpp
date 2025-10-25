class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1, ver2;
        string temp = "";

        for (auto it : version1) {
            if (it == '.') {
                ver1.push_back(stoi(temp));
                temp = "";
            } else {
                temp += it;
            }
        }
        if (!temp.empty()) ver1.push_back(stoi(temp)); 

        temp = "";
        for (auto it : version2) {
            if (it == '.') {
                ver2.push_back(stoi(temp));
                temp = "";
            } else {
                temp += it;
            }
        }
        if (!temp.empty()) ver2.push_back(stoi(temp)); 
        
        int i = 0, j = 0;
        while (i < ver1.size() || j < ver2.size()) {
            int v1 = i < ver1.size() ? ver1[i] : 0;
            int v2 = j < ver2.size() ? ver2[j] : 0;

            if (v1 < v2) return -1;
            if (v1 > v2) return 1;

            i++;
            j++;
        }

        return 0;
    }
};
