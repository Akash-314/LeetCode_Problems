class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1, temp1 = 1, temp2 = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                temp1++;
                inc = max(inc, temp1);
            } else
                temp1 = 1;
            if (nums[i - 1] > nums[i]) {
                temp2++;
                dec = max(dec, temp2);
            } else
                temp2 = 1;
            cout<<inc<<" "<<dec<<endl;
        }
        return max(inc, dec);
    }
};