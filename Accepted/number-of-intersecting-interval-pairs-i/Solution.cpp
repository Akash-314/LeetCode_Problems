class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& in) {
        int n = in.size();
        sort(in.begin(), in.end());
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(in[i][1] >= in[j][0]) cnt++;
            }
        }
        return cnt;
    }
};