class Solution {
public:
    int arr[1010];
    int combinationSum4(vector<int>& nums, int target) {
        for(int i = 0; i < 1010; i++) {
            arr[i] = -1;
        }
        arr[0] = 1;
        find_combination(nums, target);
        return arr[target];
    }
    
    int find_combination(vector<int>& nums, int target) {
        if (target < 0)
            return 0;
        if (arr[target] != -1) {
            return arr[target];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            ans += find_combination(nums, target-nums[i]);
        }
        arr[target] = ans;
        return ans;
    }
};