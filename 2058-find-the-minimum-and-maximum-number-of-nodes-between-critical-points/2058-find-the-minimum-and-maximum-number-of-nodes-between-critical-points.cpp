class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int fidx = -1;
        int sidx = -1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if (c == NULL)
            return {-1, -1};
        int minD = INT_MAX;
        int f = -1;
        int s = -1;
        while (c) {
            if (b->val < a->val && b->val < c->val ||
                b->val > a->val && b->val > c->val) {
                // MaxD
                if (fidx == -1)
                    fidx = idx;
                else
                    sidx = idx;
                f = s;
                s = idx;
                if (f != -1) {
                    int d = s - f;
                    minD = min(d, minD);
                }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if (sidx == -1)
            return {-1, -1};
        int maxD = sidx - fidx;
        return {minD, maxD};
    }
};