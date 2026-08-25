class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        mx = mx / k;
        vector<int> v;
        unordered_set<int> st;
        for(int x : nums) st.insert(x);
        for(int i = 1; i <= mx+1; i++){
            if(st.count(i * k)) st.erase(i*k);
            else return i*k;
        }
        return (mx+1) * k;
    }
};