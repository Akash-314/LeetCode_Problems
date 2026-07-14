class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int nk;
    KthLargest(int k, vector<int>& nums) {
        nk = k;
        for(int ele : nums){
            pq.push(ele);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > nk) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */