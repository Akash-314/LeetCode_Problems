class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1, newN = n;
        while (n) {
            int dig = n % 10;
            sum += dig;
            prod *= dig;
            n /= 10;
        }
        sum += prod;
        return newN % sum == 0;
    }
};