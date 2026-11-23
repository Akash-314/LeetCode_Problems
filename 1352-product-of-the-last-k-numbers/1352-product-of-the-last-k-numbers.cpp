class ProductOfNumbers {
public:
    // last k ka multiply
    // last = num
    // i++;
    // last = i-1;
    vector<int> nums;
    int i, last;
    ProductOfNumbers() {
        i = 0;
        last = 0;
    }

    void add(int num) {
        nums.push_back(num);
        i++;
    }

    int getProduct(int k) {
        int ans = 1;
        last = i - k;
        for (int j = last; j < i; j++) {
            ans *= nums[j];
            // cout<<nums[j]<<" ";
        }
        // cout<<'\n';
        return ans;
    }
};