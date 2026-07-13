class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        int a = 1;
        int maxH = 1e9;
        int d = 1;
        while(a < 10){
            int b = 0;
            while(a < 10 and b < maxH){
                b = b*10 + a;
                a++;
                v.push_back(b);
            }
            d++;
            a = d;
        }
        vector<int> ans;
        for(int i = 0; i < v.size(); i++){
            if(v[i] >= low and v[i] <= high){
                ans.push_back(v[i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};