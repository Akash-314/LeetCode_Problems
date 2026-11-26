class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        int a = 10;
        int t = 0;
        while(a > 0) {
            t++;
            n -= a;
            a--;
            if(n < a) return t & 1;
        }
        return t & 1;
    }
};