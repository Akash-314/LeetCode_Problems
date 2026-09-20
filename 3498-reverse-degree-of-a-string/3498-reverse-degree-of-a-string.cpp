class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            int x = s[i] - 'a';
            x = 26 - x;
            ans += (x * (i+1));
        }
        return ans;
    }
};