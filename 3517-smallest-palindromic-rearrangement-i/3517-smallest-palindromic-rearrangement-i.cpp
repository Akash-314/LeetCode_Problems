class Solution {
public:
    string smallestPalindrome(string s) {
        string ans = "";
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        char xtra = 0;
        for(auto &x : mp){
            if(x.second % 2){
                xtra = x.first;
                x.second--;
            }
            for(int i = 0; i < x.second/2; i++) {
                ans += x.first;
            }
        }
        string left = ans;
        if(xtra) ans += xtra;
        reverse(left.begin(), left.end());
        ans += left;
        
        return ans;
    }
};