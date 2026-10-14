class Solution {
public:
    string maxSumOfSquares(int Num, int sum) {
        string ans = "";
        long long num = Num;
        long long n = 9 * num;
        if (n < sum)
            return "";
        int a = 9;
        while (num--) {
            if (sum < a) {
                ans += ('0' + sum);
                break;
            }
            ans += ('0' + a);
            sum -= a;
        }
        while (ans.size() < Num) {
            ans += '0';
        }
        return ans;
    }
};