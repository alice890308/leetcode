class Solution {
public:
    int rob(vector<int>& nums) {
        int r = 0, n = 0; // rob, not rob
        int prev_r, prev_n;
        for(int i = 0; i < nums.size(); i++) {
            prev_r = r;
            prev_n = n;
            r = prev_n + nums[i];
            n = max(prev_r, prev_n);
        }
        return max(r, n);
    }
};