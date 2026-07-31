class Solution {
public:
    int n;
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
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {
                    Union(parent, rank, i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (find(parent, i) == i)
                cnt++;
        }
        return n - cnt;
    }
};