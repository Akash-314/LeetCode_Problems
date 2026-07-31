class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int add) {
        vector<pair<int,int>> b;
        int n = rocks.size();
        for(int i = 0; i < n; i++){
            b.push_back({cap[i] - rocks[i], cap[i]});
        }
        sort(b.begin(), b.end());
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int diff = b[i].first;
            int r = b[i].second;
            if(add >= diff){
                add -= (diff);
                cnt++;
            }else continue;
        }
        return cnt;
    }
};