class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
        int i = s[0];
        int j = s[1];
        int x = t[0];
        int y = t[1];
        if (abs(i - x) == abs(j - y)) {
            return 1;
        }
        if (i == x and j == y)
            return 0;
        if ((i + j) % 2 != (x + y) % 2)
            return -1;
        return 2;
    }
};