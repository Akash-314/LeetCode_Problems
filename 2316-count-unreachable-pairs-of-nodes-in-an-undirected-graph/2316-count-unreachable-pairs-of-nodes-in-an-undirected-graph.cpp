class Solution {
public:
    int find(vector<int>& parent, int x) {
        return parent[x] = ((parent[x] == x) ? x : find(parent, parent[x]));
    }
    void Union(vector<int>& parent, vector<int>& rank, vector<int>& sz, int a,
               int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a == b)
            return;
        if (rank[a] >= rank[b]) {
            sz[a] += sz[b];
            rank[a]++;
            parent[b] = a;
        } else {
            sz[b] += sz[a];
            rank[b]++;
            parent[a] = b;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n + 1, 0);
        vector<int> rank(n + 1, 0);
        vector<int> sz(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (auto& e : edges) {
            Union(parent, rank, sz, e[0], e[1]);
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[find(parent, i)]++;
        }

        long long rem = n, ans = 0;
        for (auto& m : mp) {
            rem -= m.second;
            ans += m.second * rem;
        }
        return ans;
    }
};