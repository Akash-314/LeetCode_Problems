class Solution {
public:
    bool canTransform(vector<int>& src, vector<int>& tar) {
        int n = src.size();
        long long sum1 = accumulate(src.begin(), src.end(), 0LL);
        long long sum2 = accumulate(tar.begin(), tar.end(), 0LL);
        return (sum1 == sum2);
    }
};