class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int t = 1;
        while(t <= mx){
            t <<= 1;
        }
        vector<bool> st1(t, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                st1[nums[i] ^ nums[j]] = true;
            }
        }
        vector<bool> st2(t, 0);
        for (int i = 0; i < t; i++) {
            if(st1[i]){
                for(int &num : nums){
                    st2[i ^ num] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < t; i++) {
            if(st2[i]) cnt++;
        }
        return cnt;
    }
};