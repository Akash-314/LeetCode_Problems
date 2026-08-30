class Solution {
public:
    vector<vector<int>> ans;
    void f(int i, int& n, int k, vector<int>& temp) {
        if (k == 0) {
            ans.push_back(temp);
            return;
        }
        if (i > n)
            return;
        temp.push_back(i);
        f(i + 1, n, k - 1, temp);
        temp.pop_back();
        f(i + 1, n, k, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        f(1, n, k, temp);
        return ans;
    }
};