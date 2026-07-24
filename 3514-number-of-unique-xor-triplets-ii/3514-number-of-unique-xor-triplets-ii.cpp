class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                st1.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> st2;
        for (int i = 0; i < n; i++) {
            for (int x : st1) {
                st2.insert(nums[i] ^ x);
            }
        }
        return st2.size();
    }
};