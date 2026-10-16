class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    bool isPalindrome(int n) {
        string s = to_string(n);
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int primePalindrome(int n) {
        int i = n;
        while (true) {
            if (i > 11 && to_string(i).size() % 2 == 0) {
                i = pow(10, to_string(i).size());
                continue;
            }
            if (isPrime(i) && isPalindrome(i)) {
                return i;
            }
            i++;
        }
        return -1;
    }
};