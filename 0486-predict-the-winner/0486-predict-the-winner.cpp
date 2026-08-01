class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& nums , int i, int j){
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(nums[i] - f(nums , i+1 , j) , nums[j] - f(nums , i , j-1));
    }
    bool predictTheWinner(vector<int>& nums) {
        dp.resize(25 , vector<int>(25, -1));
        int n = nums.size();
        return (f(nums, 0, n-1) >= 0);
    }
};