class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;
        int n = knowledge.size();
        for (int i = 0; i < n; i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        bool ok = false;
        string ans = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                i++;
                string temp = "";
                while (s[i] != ')') {
                    temp += s[i];
                    i++;
                }
                if (mp.count(temp)) {
                    ans += mp[temp];
                } else
                    ans += '?';
            } else
                ans += s[i];
            i++;
        }
        return ans;
    }
};