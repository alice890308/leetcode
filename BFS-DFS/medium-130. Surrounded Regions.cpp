class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    if (check(board, i, j)) {
                        capture(board, i, j);
                    }
                }
                    
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'C')
                    board[i][j] = 'O';
            }
        }
    }
private:
    bool check(vector<vector<char>>& board, int sr, int sc) {
        if (sr >= board.size() || sr < 0) return false;
        if (sc >= board[0].size() || sc < 0) return false;
        if(board[sr][sc] == 'X' || board[sr][sc] == 'C') return true;
        
        if (board[sr][sc] == 'O') {
            bool t1, t2, t3, t4;
            board[sr][sc] = 'C';
            t1 = check(board, sr+1, sc);
            t2 = check(board, sr-1, sc);
            t3 = check(board, sr, sc+1);
            t4 = check(board, sr, sc-1);
            if (t1 && t2 && t3 && t4)
                return true;
        }
        return false;
    }
    
    void capture(vector<vector<char>>& board, int sr, int sc) {
        if (sr >= board.size() || sr < 0) return;
        if (sc >= board[0].size() || sc < 0) return;
        if(board[sr][sc] == 'X') return;
        
        board[sr][sc] = 'X';
        capture(board, sr+1, sc);
        capture(board, sr-1, sc);
        capture(board, sr, sc+1);
        capture(board, sr, sc-1);
    }
};
