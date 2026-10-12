class Solution {
public:
    vector<int> ans;
    void sieve(vector<bool>& prime, int n, int s) {
        for (int i = 2; i * i <= n; i++) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                if (sum + i > s)
                    break;
                sum += i;
                ans.push_back(i);
            }
        }
    }
    vector<int> maxPrimes(int n, int s) {
        vector<bool> prime(n+1, true);
        sieve(prime, n, s);
        return ans;
    }
};