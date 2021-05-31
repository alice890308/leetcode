class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int> > my_matrix(matrix.size(), vector<int> (matrix[0].size()));
        int ans = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') { // 在邊邊的地方
                    my_matrix[i][j] = matrix[i][j]-'0';
                }
                else {
                    my_matrix[i][j] = min(my_matrix[i-1][j], my_matrix[i][j-1]);
                    my_matrix[i][j] = min(my_matrix[i][j], my_matrix[i-1][j-1]) + 1;
                }
                if (my_matrix[i][j] > ans)
                    ans = my_matrix[i][j];
            }
        }
        return ans*ans;
    }
};