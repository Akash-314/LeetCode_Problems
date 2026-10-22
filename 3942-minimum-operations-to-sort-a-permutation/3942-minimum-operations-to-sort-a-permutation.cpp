class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        vector<int> arr = nums;
        reverse(arr.begin(), arr.end());
        if(n == 1) return nums[0] == 0 ? 0 : -1;
        if(n == 2){
            if(nums[0] == 0 and nums[1] == 1) return 0;
            if(nums[0] == 1 and nums[1] == 0) return 1;
            return -1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == 0) {
                if ((nums[i - 1] != n - 1 and nums[i - 1] != 1) or
                    (nums[i + 1] != n - 1 and nums[i + 1] != 1))
                    return -1;
                continue;
            }
            if (nums[i] != 0 and nums[i + 1] != 0) {
                if (abs(nums[i] - nums[i + 1]) > 1)
                    return -1;
            }
            if ((nums[i - 1] > nums[i] and nums[i] < nums[i + 1]) or
                (nums[i - 1] > nums[i] and nums[i] < nums[i + 1]))
                peak++;
        }
        if (peak > 1)
            return -1;

        int i = 0, j = 0;
        while (nums[i] != 0)
            i++;
        while (arr[j] != 0)
            j++;
        if (i == 0) {
            if (nums[i + 1] == 1)
                return 0;
            return 2;
        }
        if (i == n - 1) {
            if (nums[i - 1] == 1) {
                return 1;
            }
            if (nums[0] == 1) {
                if (n <= 3)
                    return i;
                return 3;
            }
        }

        if (nums[i - 1] == n - 1) {
            return min(i, j + 3);
        }
        if (nums[i - 1] == 1) {
            return min(i + 2, j + 1);
        }
        return -1;
    }
};