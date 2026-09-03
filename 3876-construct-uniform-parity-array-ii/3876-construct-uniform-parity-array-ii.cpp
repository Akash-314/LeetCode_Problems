class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool isEven = true, flag = true;
        int mn = INT_MAX, mne = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2)
                mn = min(nums1[i], mn);
            if (nums1[i] % 2)
                isEven = false;
            if (nums1[i] % 2 == 0)
                mne = min(mne, nums1[i]);
        }
        if (isEven)
            return true;
        if (mne > mn)
            return true;
        return false;
    }
};