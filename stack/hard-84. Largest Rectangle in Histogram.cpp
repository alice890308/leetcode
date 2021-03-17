class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int prev_less[100010], next_less[100010];
        vector<pair<int, int> > stk; // first is heights, second is index
        int ans = 0;
        int range;
        int temp;
        
        // init
        for(int i = 0; i < 10010; i++) {
            prev_less[i] = -1;
            next_less[i] = -1;
        }
        
        // find all index of previous less number
        for(int i = 0; i < heights.size(); i++) {
            while(!stk.empty() && stk[stk.size()-1].first >= heights[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) {
                prev_less[i] = stk[stk.size()-1].second;
            }
            stk.push_back(make_pair(heights[i], i));
        }
        stk.clear();
        
        // find all index of next less number
        for(int i = heights.size()-1; i >= 0; i--) {
            while(!stk.empty() && stk[stk.size()-1].first >= heights[i]) {
                stk.pop_back();
            }
            if (!stk.empty()) {
                next_less[i] = stk[stk.size()-1].second;
            } else { // 在這個數字之後沒有比他更小的heights
                next_less[i] = heights.size();
            }
            stk.push_back(make_pair(heights[i], i));
        }
        
        for(int i = 0; i < heights.size(); i++) {
            range = next_less[i] - prev_less[i] - 1;
            temp = heights[i] * range;
            if (temp > ans) {
                ans = temp; 
            }
        }
        
        return ans;
    }
};
