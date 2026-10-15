class Solution {
public:
#define ll long long
    long long interchangeableRectangles(vector<vector<int>>& rect) {
        int n = rect.size();
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++) {
            int h = rect[i][0];
            int w = rect[i][1];
            int g = __gcd(h, w);
            int p = h / g;
            int l = w / g;

            mp[{p, l}]++;
        }
        ll ans = 0;
        for(auto x : mp){
            int a = x.first.first;
            int b = x.first.second;
            cout<<a<<" "<<b<<endl;
            ll cnt = x.second;
            ans += (cnt * (cnt - 1))/2;
        }
        return ans;
    }
};