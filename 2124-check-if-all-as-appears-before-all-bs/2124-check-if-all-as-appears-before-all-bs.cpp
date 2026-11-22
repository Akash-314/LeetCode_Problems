class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int cntA = count(s.begin(), s.end(), 'a');
        int cntB = count(s.begin(), s.end(), 'b');
        if(cntB == n or cntA == n) return true;
        int i = 0;
        while(i < n and s[i] == 'a') i++;
        while(i < n){
            if(s[i] == 'a') return false;
            i++;
        }
        return true;
    }
};