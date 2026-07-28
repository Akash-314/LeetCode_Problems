class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            pre[i] = max(pre[i-1], nums[i-1]);
            suf[n-i-1]=min(suf[n-i],nums[n-i]);
        }
        long long ans = 0;
        for(int i = 1; i < n-1; i++){
            if(nums[i] > pre[i] and nums[i] < suf[i]){
                ans += 2;
            }else if(nums[i] > nums[i-1] and nums[i] < nums[i+1]){
                ans += 1;
            }
        }
        return ans;
    }
};