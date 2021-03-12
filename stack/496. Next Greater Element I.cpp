using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int arr[10010];
        int len2 = nums2.size();
        int len1 = nums1.size();
        int t;
        vector<int> ans;
        
        // init
        for(int i = 0; i < 10010; i++) {
            arr[i] = -1;
        }
        
        for(int i = len2-1; i >= 0; i--) {
            while(!stk.empty() && nums2[i] > stk.top()) {
                stk.pop();
            }
            if (!stk.empty()) {
                arr[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        }
        
        for(int i = 0; i < len1; i++) {
            ans.push_back(arr[nums1[i]]);
        }
        return ans;
    }
};
