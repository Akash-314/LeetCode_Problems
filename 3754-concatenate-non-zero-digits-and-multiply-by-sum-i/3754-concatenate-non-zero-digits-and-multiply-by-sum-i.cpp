class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = 0;
        long long mul = 0;
        while(n){
            int d = n % 10;
            n /= 10;
            if(d != 0) {
                num = num*10 + d;
                mul += d;
            }
        }
        return rev(num) * mul;
    }
    int rev(int n){
        int res = 0;
        while(n){
            int d = n % 10;
            n /= 10;
            res = res*10 + d;
        }
        return res;
    }
};