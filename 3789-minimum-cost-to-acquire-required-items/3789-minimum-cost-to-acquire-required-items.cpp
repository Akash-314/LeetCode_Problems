class Solution {
public:
#define ll long long
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll ans1, ans2, ans3, ans4;
        ans1 = 1LL * max(need1, need2) * costBoth;
        ans2 = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        ans3 = (need1 > need2)
                   ? 1LL * need2 * (cost1 + cost2) + 1LL * need1 * costBoth
                   : 1LL * need1 * (cost1 + cost2) + 1LL * need2 * costBoth;
        ans4 = 1LL * min(need1, need2) * costBoth +
               1LL * ((need1 > need2) ? 1LL * (need1 - need2) * cost1
                                      : 1LL * (need2 - need1) * cost2);
        return min({ans1, ans2, ans3, ans4});
    }
};