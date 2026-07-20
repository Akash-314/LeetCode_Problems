class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.size();
        int cycle = 2 * numRows - 2;
        int full = n / cycle;
        int rem = n % cycle;
        int col = full * (numRows - 1);
        if (rem > 0) {
            if (rem <= numRows)
                col += 1;
            else
                col += 1 + (rem - numRows);
        }
        vector<vector<char>> v(numRows, vector<char>(col, '*'));
        int a = 0;
        int i = 0, j = 0;
        while (a < n) {
            while (i < numRows && a < n) {
                v[i][j] = s[a++];
                i++;
            }
            i -= 2;
            j++;
            while (i > 0 && a < n) {
                v[i][j] = s[a++];
                i--;
                j++;
            }

            i = 0;
        }
        string res = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < col; j++) {
                if (v[i][j] != '*')
                    res += v[i][j];
            }
        }
        return res;
    }
};