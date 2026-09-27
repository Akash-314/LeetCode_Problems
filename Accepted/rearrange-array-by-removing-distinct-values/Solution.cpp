class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> v(101, 0);
        for (int i = 0; i < n; i++){
              v[nums[i]]++;
                // cout<<v[nums[i]]<<" ";
        }
          
        while (ans.size() < n) {
            for (int i = 1; i <= 100; i++) {
                if (v[i] > 0) {
                    ans.push_back(i);
                    v[i]--;
                }
            }
        }
        return ans;
    }
};