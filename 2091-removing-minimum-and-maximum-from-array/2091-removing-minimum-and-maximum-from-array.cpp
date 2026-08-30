class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int x,y, mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] < mn){
                x = i;
                mn = nums[i];
            }
            if(nums[i] > mx){
                y = i;
                mx = nums[i];
            }
        }
        int ans = INT_MAX;
        if(mx==mn) ans=min(y+1,n-y);
        else{
            ans=min(ans,max(y,x)+1);
            ans=min(ans,n-min(y,x));
            ans=min(ans,min(y,x)+1+n-max(y,x));
        }
        return ans;
    }
};