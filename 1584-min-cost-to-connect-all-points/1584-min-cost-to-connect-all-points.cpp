class Solution {
public:
    int find(vector<int>& par, int x) {
        return par[x] = (par[x] == x) ? x : find(par, par[x]);
    }
    void Union(vector<int>& par, vector<int>& rank, int a, int b) {
        a = find(par, a);
        b = find(par, b);
        if (rank[a] >= rank[b]) {
            rank[a]++;
            par[b] = a;
        } else {
            rank[b]++;
            par[a] = b;
        }
    }
    static bool cmp(vector<int>& a, vector<int>& b) { return a[2] < b[2]; }
    long long Kruskals(vector<vector<int>>& input, int n) {
        sort(input.begin(), input.end(), cmp);
        vector<int> par(n + 1);
        vector<int> rank(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
        long long edgeCnt = 0, ans = 0;
        int i = 0;
        while (edgeCnt < n - 1 and i < input.size()) {
            auto curr = input[i];
            int srcPar = find(par, curr[0]);
            int destPar = find(par, curr[1]);
            if (srcPar != destPar) {
                Union(par, rank, srcPar, destPar);
                ans += curr[2];
                edgeCnt++;
            }
            i++;
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int wt = abs(x2 - x1) + abs(y2 - y1);
                adj.push_back({i, j, wt});
            }
        }
        return Kruskals(adj, n);
    }
};