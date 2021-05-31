/* IDDFS */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int> > updated(matrix.size(), vector<int> (matrix[0].size()));
        vector<vector<bool> > visited(matrix.size(), vector<bool> (matrix[0].size()));
        int steps;
        bool temp;
        
        // init
        for(int i = 0; i < updated.size(); i++){
            for(int j = 0; j < updated[0].size(); j++){
                if (matrix[i][j] == 0)
                    updated[i][j] = 0;
                else
                    updated[i][j] = -1;
                visited[i][j] = false;
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if (updated[i][j] != -1)
                    continue;
                steps = 0;
                while(++steps) {
                    temp = IDDFS(matrix, visited, updated, i, j, steps);
                    if (temp)
                        break;
                }
            }
        }
        return updated;
    }

private:
    bool IDDFS(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>>& updated, int row, int col, int limit_steps) {
        bool temp;
        
        if (row < 0 || row >= matrix.size()) return false;
        if (col < 0 || col >= matrix[row].size()) return false;
        if (visited[row][col]) return false;
        if (limit_steps == updated[row][col]) {
            return true;
        }
        else if (limit_steps < updated[row][col]) {
            return false;
        }
        if (limit_steps == 0) {
            if (matrix[row][col] == 0)
                return true;
            return false;
        }

        visited[row][col] = true;
        temp = IDDFS(matrix, visited, updated, row+1, col, limit_steps-1);
        if (!temp) temp = IDDFS(matrix, visited, updated, row-1, col, limit_steps-1);
        if (!temp) temp = IDDFS(matrix, visited, updated, row, col-1, limit_steps-1);
        if (!temp) temp = IDDFS(matrix, visited, updated, row, col+1, limit_steps-1);
        if (temp) {
            updated[row][col] = limit_steps;
            visited[row][col] = false;
            return true;
        }
        visited[row][col] = false;
        return false;
    }
};
