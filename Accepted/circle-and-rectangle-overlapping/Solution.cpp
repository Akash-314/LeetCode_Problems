class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        bool ans = false;
        int px = max(x1, min(xCenter, x2));
        int py = max(y1, min(yCenter, y2));
        int d = (xCenter - px)*(xCenter - px) + (yCenter - py)*(yCenter - py);
        if(d <= radius*radius) return true;
        else return false;
    }
};