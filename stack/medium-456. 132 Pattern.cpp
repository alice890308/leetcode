/*
for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
        if (min-in-arr[0~i-1] < arr[j] && arr[j] < arr[i]);
    }
}

for(int i = n-1; i >= 0; i--) {
    for(int j = i+1; j < n; j++) {
        if (min-in-arr[0~i-1] < arr[j] && arr[j] < arr[i]);
    }
}
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        vector<int> stk;
        vector<int> minimum;
        
        /* find min in num[0]~num[i] */
        minimum.push_back(INT_MAX);
        for(int i = 1; i < len; i++) {
            minimum.push_back(min(minimum[i-1], nums[i-1]));
        }
        
        for(int i = 0; i < len; i++) {
            while(!stk.empty() && nums[stk[stk.size()-1]] <= nums[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) {
                if (minimum[stk[stk.size()-1]] < nums[i]) {
                    return true;
                }
            }
            stk.push_back(i);
        }
        return false;
    }
};
