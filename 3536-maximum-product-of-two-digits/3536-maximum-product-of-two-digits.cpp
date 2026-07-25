class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0;
        int mx2 = 0;
        while(n){
            int d = n % 10;
            if(d >= mx1){
                mx2 = mx1;
                mx1 = d;
            }else mx2 = max(mx2, d);
            n /= 10;
        }
        return 1LL * mx1 * mx2;
    }
};