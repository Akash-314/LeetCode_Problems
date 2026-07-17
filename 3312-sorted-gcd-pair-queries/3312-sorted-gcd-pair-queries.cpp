class Solution {
public:
    typedef long long ll;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries){
        int n = nums.size();
        int mx = *max_element(begin(nums), end(nums));

        vector<int> freq(mx+1, 0);

        for(int i = 0; i < n; i++){
            int num = nums[i];

            for(int j = 1; j*j <= num; j++){
                if(num % j == 0) {
                    freq[j]++;
                if(num / j != j) {
                    freq[num/j]++;
                }
                }
            }
        }
        vector<ll> gcdPair(mx + 1, 0);
        for(int g = mx; g >= 1; g--) {
            ll count = freq[g];
            gcdPair[g] = count * (count-1)/2;

            for(int m = 2*g; m <= mx; m+= g){
                gcdPair[g] -= gcdPair[m];
            }
        }
        vector<ll> pref(mx + 1, 0);
        for(int g = 1; g <= mx; g++){
            pref[g] = pref[g-1] + gcdPair[g];
        }
        vector<int> res;

        for(ll idx : queries){
            int l = 1;
            int r = mx;
            int temp = 1;
            while(l <= r) {
                int mid = l + (r-l)/2;

                if(pref[mid] > idx){
                    temp = mid;
                    r = mid - 1;
                }else l = mid + 1;
            }
        res.push_back(temp);
        }
        return res;
    }
};