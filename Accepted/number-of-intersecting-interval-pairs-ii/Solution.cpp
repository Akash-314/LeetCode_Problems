class Solution {
public:
    #define ll long long
    long long countIntersectingIntervals(vector<vector<int>>& v) {
        int n = v.size();
        ll ans = 0;
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &x : v){
            int l = x[0];
            while(!pq.empty() and pq.top() < l) pq.pop();

            ans += pq.size();
            pq.push(x[1]);
        }
        return ans;
    }
};