class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        mx = mx / k;
        vector<int> v;
        unordered_set<int> st;
        for(int x : nums) st.insert(x);
        for(int i = 1; i <= mx; i++){
            v.push_back(k * i);
        }
        for(int i = 0; i < v.size(); i++){
            if(st.count(v[i])) st.erase(v[i]);
            else return v[i];
        }
        return (v.size()+1) * k;
    }
};