class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(i == j or j == k or i == k or nums[i] == 0) continue;
                        int num = nums[i]*100 + nums[j]*10 + nums[k];
                        if(num % 2 == 0) st.insert(num);
                }
            }
        }
        return st.size();
    }
};