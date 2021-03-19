/*
O(N^2) solution, using dynamic programming
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int arr[2510]; // record the length of longest subsequence, which the number is at the right most place
        int cur_longest = 0;
        
        // init
        for(int i = 0; i < 2510; i++) {
            arr[i] = 1;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            cur_longest = 0;
            for(int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && arr[j] > cur_longest) {
                    cur_longest = arr[j];
                }
            }
            arr[i] += cur_longest;
        }
        cur_longest = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (arr[i] > cur_longest) {
                cur_longest = arr[i];
            }
        }
        
        return cur_longest;
    }
};
