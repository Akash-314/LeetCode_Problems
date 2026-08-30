class Solution {
public:
    int f(vector<int>& nums){
        int n = nums.size();
        int cnt = 0;
        vector<int> pre(n), suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            pre[i] = __gcd(pre[i-1], nums[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            suf[i] = __gcd(suf[i+1], nums[i]);
        }
        for(int j = 0; j < n-1; j++){
            if(pre[j] == suf[j+1]) cnt++;
        }
        return cnt;
    }
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = f(nums);
        vector<int> temp(n-1);
        for(int i = 0; i < n; i++){
            int k = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                temp[k++] = nums[j];
            }
            ans = max(ans, f(temp));
        }
        return ans;
    }
};