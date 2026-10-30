class Solution {
public:
    int candy(vector<int>& rate) {
        int n = rate.size();
        int ans = 0;
        vector<int> left(n), right(n);
        left[0] = 1, right[n-1] = 1;
        for(int i = 1; i < n; i++){
            if(rate[i-1] < rate[i]){
                left[i] = left[i-1] + 1;
            }else left[i] = 1;
            cout<<left[i]<<endl;
        }
        for(int i = n-2; i >= 0; i--){
            if(rate[i+1] < rate[i]){
                right[i] = right[i+1] + 1;
            }else right[i] = 1;
        }

        for(int i = 0; i < n; i++){
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};