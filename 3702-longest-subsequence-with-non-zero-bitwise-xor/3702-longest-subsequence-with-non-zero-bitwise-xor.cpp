class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            x ^= nums[i];
            if(nums[i] != 0) cnt = 1;
        }
        if(x) return n;
        if(!cnt) return 0;
        for(int i = 0; i < n; i++){
            if(x ^ nums[i] != 0) return n-1;
        }
        return n;
    }
};