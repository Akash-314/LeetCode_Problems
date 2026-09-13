class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> pos[105];
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
                pos[nums[i]].push_back(i);
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++){
            if(pos[i].size() == 3){
                if(pos[i][1] - pos[i][0] == pos[i][2] - pos[i][1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};