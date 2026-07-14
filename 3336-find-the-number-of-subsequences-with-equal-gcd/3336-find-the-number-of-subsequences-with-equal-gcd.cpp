class Solution {
public:
    typedef long long ll;
    int mod = 1000000007;
    long long dp[201][201][201];
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return (int)f(nums, 0, 0, 0);
    }
    int f(vector<int> &nums, int i, ll fst, ll scnd){
        if(i == nums.size()){
            if(fst != 0 and scnd != 0){
                if(fst == scnd) return 1;
            }
            return 0;
        }
        if(dp[i][fst][scnd] != -1) return dp[i][fst][scnd];
        ll skip = f(nums, i+1, fst, scnd);
        ll take1 = f(nums, i+1, __gcd<ll>(fst,nums[i]), scnd);
        ll take2 = f(nums, i+1, fst,  __gcd<ll>(scnd,nums[i]));
        return dp[i][fst][scnd] = (0LL + skip + take1 + take2) % mod;
    }
};