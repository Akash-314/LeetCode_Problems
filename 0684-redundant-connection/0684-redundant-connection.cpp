class Solution {
public:
    int find(vector<int>& parent, int x) {
        return parent[x] = ((parent[x] == x) ? x : find(parent, parent[x]));
    }
    void Union(vector<int>& parent, vector<int>& rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if (a == b)
            return;
        if (rank[a] >= rank[b]) {
            rank[a]++;
            parent[b] = a;
        } else {
            rank[b]++;
            parent[a] = b;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            if (find(parent, x) == find(parent, y))
                return {x, y};
            else
                Union(parent, rank, x, y);
        }
        return {};
    }
};