class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<string> ans;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            unordered_map<char,int>mp;
            string temp = "";
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                temp += s[j];
                if(temp.size() > mn) break;
                if(mp['1'] == k) {
                    mn = min(mn, (int)temp.size());
                    ans.push_back(temp);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        // for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<endl;
        for(string str : ans){
            if(str.size() == mn) return str;
        }
        return {};
    }
};