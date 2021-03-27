/* IDDFS version */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int> > updated(matrix.size(), vector<int> (matrix[0].size()));
        vector<vector<int> > tried(matrix.size(), vector<int> (matrix[0].size())); // 紀錄每個位置已經嘗試過走幾步了
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
                tried[i][j] = 0;
                visited[i][j] = false;
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if (updated[i][j] != -1)
                    continue;
                steps = tried[i][j];
                while(++steps) {
                    //cout << " i = " << i << " , j = " << j << '\n';
                    temp = IDDFS(matrix, tried, visited, updated, i, j, steps);
                    if (temp)
                        break;
                }
            }
        }
        return updated;
    }

private:
    bool IDDFS(vector<vector<int>>& matrix, vector<vector<int>>& tried, vector<vector<bool>>& visited, vector<vector<int>>& updated, int row, int col, int limit_steps) {
        bool temp;
        
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
        
        if (limit_steps > tried[row][col])
            tried[row][col] = limit_steps;
        
        visited[row][col] = true;
        if (row+1 < matrix.size() && visited[row+1][col] == false) {
            temp = IDDFS(matrix, tried, visited, updated, row+1, col, limit_steps-1);
            if (temp == true) {
                updated[row][col] = limit_steps;
                visited[row][col] = false;
                return true;
            }
        }
        if (row-1 >= 0 && visited[row-1][col] == false) {
            //cout << "row-1 = " << row-1 << " , col = " << col << '\n';
            temp = IDDFS(matrix, tried, visited, updated, row-1, col, limit_steps-1);
            //cout << temp << '\n';
            if (temp == true) {
                updated[row][col] = limit_steps;
                visited[row][col] = false;
                return true;
            }
        }
        if (col-1 >= 0 && visited[row][col-1] == false) {
            temp = IDDFS(matrix, tried, visited, updated, row, col-1, limit_steps-1);
            if (temp == true) {
                updated[row][col] = limit_steps;
                visited[row][col] = false;
                return true;
            }
        }
        if (col+1 < matrix[row].size() && visited[row][col+1] == false) {
            temp = IDDFS(matrix, tried, visited, updated, row, col+1, limit_steps-1);
            if (temp == true) {
                updated[row][col] = limit_steps;
                visited[row][col] = false;
                return true;
            }
        }
        visited[row][col] = false;
        return false;
    }
};
