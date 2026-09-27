class Solution {
public:
    int minQueenMoves(vector<int>& src, vector<int>& tar) {
        int sRow = src[0];
        int sCol = src[1];
        if(sRow == tar[0] and sCol == tar[1]) return 0;
        if(sRow == tar[0] or sCol == tar[1]) return 1;
        int x = tar[0];
        int y = tar[1];
        if(abs(sCol-y) == abs(sRow - x)) return 1;
        return 2;
    }
};