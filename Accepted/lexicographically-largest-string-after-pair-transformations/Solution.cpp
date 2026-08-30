class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        int z = 1 << 25;
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string s = "";
            int cnt = nums[i] / z;
            int rem = nums[i] % z;

            for (int j = 0; j < cnt; j++) {
                s += 'z';
            }
            for (int k = 24; k >= 0; k--) {
                if ((rem >> k) & 1) {
                    s += (char)('a' + k);
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};