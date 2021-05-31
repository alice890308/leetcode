class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i < triangle.size(); i++) {
            triangle[i][0] = triangle[i-1][0]+triangle[i][0];
            for(int j = 1; j < triangle[i].size()-1; j++) {
                triangle[i][j] = min(triangle[i-1][j-1], triangle[i-1][j]) + triangle[i][j];
            }
            int len = triangle[i].size();
            triangle[i][len-1] = triangle[i-1][len-2] + triangle[i][len-1];
        }
        
        int minimum = 0x3f3f3f3f;
        for(auto num : triangle[triangle.size()-1]) {
            minimum = (num < minimum) ? num : minimum;
        }
        return minimum;
    }
};