class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt = count(begin(s), end(s), '1');
        vector<int> v;
        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                int start = i;
                while(i < n and s[i] == '0') i++;
                v.push_back(i - start);
            }else i++;
        }
        int mx = 0;
        for (int i = 1; i < v.size(); i++) {
            mx = max(mx, v[i] + v[i - 1]);
        }
        return mx + cnt;
    }
};