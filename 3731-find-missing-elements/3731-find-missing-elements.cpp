class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[n-1];
        unordered_set<int> st;
        for(int x: nums){
            st.insert(x);
        }
        for(int i = a; i < b; i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};