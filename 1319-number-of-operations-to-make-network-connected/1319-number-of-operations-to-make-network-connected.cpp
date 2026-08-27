class Solution {
public:
    int find(vector<int>& par, int x) {
        return par[x] = ((par[x] == x) ? x : find(par, par[x]));
    }
    void Union(vector<int>& par, vector<int>& rank, vector<int>& sz, int a,
               int b) {
        a = find(par, a);
        b = find(par, b);

        if (a == b)
            return;
        if (rank[a] >= rank[b]) {
            sz[a] += sz[b];
            rank[a]++;
            par[b] = a;
        } else {
            sz[b] += sz[a];
            rank[b]++;
            par[a] = b;
        }
    }
    int makeConnected(int n, vector<vector<int>>& edge) {
        vector<int> par(n + 1);
        vector<int> rank(n + 1, 0);
        vector<int> sz(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
        int cntX = 0;
        for (auto e : edge) {
            int u = e[0];
            int v = e[1];

            if (find(par, u) == find(par, v)) {
                cntX++;
            } else {
                Union(par, rank, sz, u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) { // to find connected component 
            if (par[i] == i)
                cntC++;
        }
        int ans = cntC - 1;
        if (cntX >= ans) {
            return ans;
        }
        return -1;
    }
};