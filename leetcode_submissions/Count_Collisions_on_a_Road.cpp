class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int count = 0;

        for (char dir : directions) {
            if (dir == 'L') {
                if (st.empty()) {
                    st.push(dir);
                }
                else if (st.top() == 'R') {
                    count += 2;
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        count++;
                        st.pop();
                    }
                    st.push('S');
                }
                else if (st.top() == 'S') {
                    count++;
                }
                else {
                    st.push(dir);
                }
            }
            else if (dir == 'S') {
                if (!st.empty() && st.top() == 'R') {
                    count++;
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        count++;
                        st.pop();
                    }
                    st.push('S');
                }
                else {
                    st.push(dir);
                }
            }
            else {
                st.push(dir);
            }
        }

        return count;
    }
};
