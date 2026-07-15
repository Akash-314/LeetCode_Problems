class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even = 0, odd = 0;
        int i = 1;
        while (i <= 2 * n) {
            if (i % 2 == 0) even += i;
            else odd += i;
            i++;
        }
        return __gcd(even, odd);
    }
};