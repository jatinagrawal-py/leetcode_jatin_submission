class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto idx = upper_bound(letters.begin(),letters.end(),target);

        if(idx == letters.end())return letters[0];


        return letters[idx-letters.begin()];
    }
};