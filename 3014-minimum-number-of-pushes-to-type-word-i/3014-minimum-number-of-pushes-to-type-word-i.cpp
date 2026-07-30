class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8) return n;
        int ans = 0;
        int cnt = n/8;
        int rem = n%8, i = 1;
        while(cnt--){
            ans += i*8;
            i++;
        }
        ans += i*rem;
        return ans;
    }
};