class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int ele: nums){
            if(st.count(ele)) st.erase(ele);
            else st.insert(ele);
        }
        vector<int> ans;
        for(int ele: st){
            ans.push_back(ele);
        }
        return ans;
    }
};