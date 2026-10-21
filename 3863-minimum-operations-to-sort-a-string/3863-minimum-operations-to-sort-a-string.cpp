class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (n == 1)
            return 0;

        string srtd = s;
        sort(srtd.begin(), srtd.end());

        if (s == srtd)
            return 0;

        if (n == 2)
            return -1;

        char mini = 'z', maxi = 'a';

        for (int i = 0; i < n; i++) {
            mini = min(mini, s[i]);
            maxi = max(maxi, s[i]);
        }

        if (s[0] == mini || s[n - 1] == maxi)
            return 1;

        if (s[0] == maxi && s[n - 1] == mini) {
            string temp1(s.begin(), s.end() - 1);
            sort(temp1.begin(), temp1.end());
            temp1 += s[n - 1];

            string temp2(temp1.begin() + 1, temp1.end());
            sort(temp2.begin(), temp2.end());
            temp2.insert(temp2.begin(), temp1[0]);

            if (temp2 == srtd)
                return 2;

            string temp3(s.begin() + 1, s.end());
            sort(temp3.begin(), temp3.end());
            temp3.insert(temp3.begin(), s[0]);

            string temp4(temp3.begin(), temp3.end() - 1);
            sort(temp4.begin(), temp4.end());
            temp4 += temp3[n - 1];

            if (temp4 == srtd)
                return 2;

            return 3;
        }

        return 2;
    }
};