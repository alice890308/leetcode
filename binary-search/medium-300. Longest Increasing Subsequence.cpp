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

/*
O(NlgN) solution
1. 陣列arr中儲存目前被挑選到的數字。
2. lower_bound會用二分搜找到大於等於指定數值的第一個數字。
3. 遍歷nums，搜尋arr中是否有比當前數字更大的數
    3-1. 若無，則直接把當前數字加到arr中
    3-2. 若有，則把該數字的位置用當前數字取代(為了不破壞increasing subsequence在nums中的順序)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        
        for(int i = 0; i < nums.size(); i++) {
            if (arr.empty() || nums[i] > arr.back()) {
                arr.push_back(nums[i]);
            }
            else {
                *lower_bound(arr.begin(), arr.end(), nums[i]) = nums[i];
            }
        }
        
        return arr.size();
    }
};
