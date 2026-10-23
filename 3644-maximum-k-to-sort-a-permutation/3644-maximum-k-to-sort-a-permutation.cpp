class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        while(j < n and nums[j] == j) j++;
        if(j >= n-1) return 0;
        int a = nums[j];
        for (int i = j; i < n; i++) {
            if(nums[i] != i){
                a &= nums[i];
            }
        }
        return a;
    }
};