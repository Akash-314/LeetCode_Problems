class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head) return NULL;
        ListNode* temp = head;
        vector<int> v;
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        vector<int> suf(n);
        suf[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], v[i]);
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp2 = &dummy;
        temp = head;
        int i = 0;
        while (temp) {
            if (temp->val < suf[i]) {
                temp2->next = temp->next;
            } else {
                temp2 = temp;
            }

            temp = temp->next;
            i++;
        }
        return dummy.next;
    }
};