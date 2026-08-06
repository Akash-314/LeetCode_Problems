class Solution {
public:
    #define ll long long
    int digMul(int n){
        ll res = 1;
        while(n){
            int d = n % 10;
            n /= 10;
            res *= d;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(true){
            ll x = digMul(i);
            if(x % t == 0) return i;
            i++;
        }
        return 0;      
    }
};