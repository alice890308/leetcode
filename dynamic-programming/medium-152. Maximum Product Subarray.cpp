class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans, max_product, min_product;
        ans = max_product = min_product = nums[0];
        int t1, t2;
        for(int i = 1; i < nums.size(); i++) {
            t1 = max_product * nums[i];
            t2 = min_product * nums[i];
            max_product = max(max(t1, t2), nums[i]);
            min_product = min(min(t1, t2), nums[i]);
            if (max_product > ans) ans = max_product;
        }
        return ans;
    }
};