class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xz = abs(z-x);
        int yz = abs(z-y);

        if(xz == yz)return 0;

        if(xz > yz)return 2;
        return 1;
    }
};