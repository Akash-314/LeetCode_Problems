class Solution {
public:
    void bfs(int src, unordered_set<int> &vis, vector<vector<int>> &adj){
        queue<int> q;
        q.push(src);
        vis.insert(src);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto neigh : adj[curr]){
                if(!vis.count(neigh)){
                    vis.insert(neigh);
                    q.push(neigh);
                }
            } 
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<int> ans;
        int m = inv.size();
        vector<vector<int>> adj(n);
        for(auto &e : inv){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        unordered_set<int> vis;
        bfs(k, vis, adj);
        for(auto &e : inv){
            int u = e[0];
            int v = e[1];
            if(!vis.count(u) && vis.count(v)){
                ans.clear();
                for(int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};