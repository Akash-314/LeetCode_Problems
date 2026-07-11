class Solution {
public:
    // void dfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &vis, int &e, int &v){
    //     if(vis[i]) return;
    //     vis[i] = true;
    //     v++;
    //     e += adj[i].size();
    //     for(auto &neigh: adj[i])
    //         if(!vis[neigh]){
    //             dfs(neigh, adj, vis, e, v);
    //         }
    // }
    void bfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &vis, int &e, int &v){
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            v++;
            e += adj[node].size();
            for(auto &neigh : adj[node]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            int e = 0;
            int v = 0;

            bfs(i, adj, vis, e, v);
            if(v*(v-1) == e) ans++;
        }
        return ans;
    }
};