class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st, st2;
        int prev = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] != prev and st2.count(nums[i])){
                st.insert(nums[i]);
            }
            st2.insert(nums[i]);
            prev = nums[i];
        }
        return st2.size() - st.size();
    }
};