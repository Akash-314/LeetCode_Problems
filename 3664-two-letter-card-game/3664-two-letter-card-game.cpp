class Solution {
public:
    int score(vector<string>& cards, char x) {
        int n = cards.size();
        int scr = 0, cnt = 0;
        unordered_map<string, int> mp1, mp2;
        for(int i = 0; i < n; i++){
            if(cards[i][0] == x and cards[i][1] == x){
                cnt++;
                continue;
            }
            if(cards[i][0] == x){
                mp1[cards[i]]++;
                continue;
            }
            if(cards[i][1] == x){
                mp2[cards[i]]++;
            }
        }
        int m1 = 0, m2 = 0;
        int c1 = 0, c2 = 0;
        for(auto m: mp1){
            m1 += m.second;
            c1 = max(c1, m.second);
        }
        for(auto m: mp2){
            m2 += m.second;
            c2 = max(c2, m.second);
        }
        int p1 = min(m1 / 2, m1 - c1);
        int p2 = min(m2 / 2, m2 - c2);
        int base = p1 + p2;
        int rem1 = m1 - 2 * p1;
        int rem2 = m2 - 2 * p2;
        int rem = rem1 + rem2;
        int ans = 0;
        for(int d = 0; d <= base; d++) {
            int pairs = base - d;
            int available = rem + 2 * d;
            ans = max(ans, pairs + min(cnt, available));
        }

        return ans;
    }
};