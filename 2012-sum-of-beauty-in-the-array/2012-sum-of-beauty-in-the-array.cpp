class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = -1;
        suf[n-1] = 1e6;
        for(int i = 1; i < n; i++){
            pre[i] = max(pre[i-1], nums[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
            suf[i] = min(suf[i+1], nums[i+1]);
        }
        long long ans = 0;
        for(int i = 1; i < n-1; i++){
            if(nums[i] > pre[i] and nums[i] < suf[i]){
                ans += 2;
            }else if(nums[i] > nums[i-1] and nums[i] < nums[i+1]){
                ans += 1;
            }else continue;
        }
        return ans;
    }
};