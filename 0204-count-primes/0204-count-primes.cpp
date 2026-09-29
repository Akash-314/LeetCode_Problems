class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        // Only store odd numbers.
        // index i represents number (2*i + 1)
        vector<bool> isPrime(n / 2, true);
        int count = 1; // prime 2
        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i / 2]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j / 2] = false;
                }
            }
        }
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i / 2])
                count++;
        }
        return count;
    }
};