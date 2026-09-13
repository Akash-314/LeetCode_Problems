class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pos[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto it : pos){
            int m = it.second.size();
            if(m < 3) continue;
            int diff = it.second[1] - it.second[0];
            bool ok = true;

            for(int i = 2; i < m; i++){
                if(it.second[i] - it.second[i-1] != diff){
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }
        return ans;
    }
};