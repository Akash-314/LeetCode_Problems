class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool KMPSearch(vector<int>& pat, vector<int>& txt) {
        int N = txt.size();
        int M = pat.size();

        if (M == 0) return true;
        vector<int> lps(M, 0);
        computeLPS(pat, lps);
        int i = 0, j = 0;
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == M)
                return true;
            else if (i < N && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }

    bool isRotationPossible(vector<int>& vec1, vector<int>& vec2) {
        if (vec1.size() != vec2.size())
            return false;
        vector<int> text = vec2;
        text.insert(text.end(), vec2.begin(), vec2.end());
        return KMPSearch(vec1, text);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int res = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            bool valid = true;

            for (int start = 0; start < n; start += k) {
                vector<int> v1(nums.begin() + start, nums.begin() + start + k);
                vector<int> v2(sorted.begin() + start, sorted.begin() + start + k);
                if (!isRotationPossible(v1, v2)) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                res += k;
        }
        return res;
    }
};