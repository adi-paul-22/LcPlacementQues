class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> copy = board;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) {
                    for (int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++) {
                        live += copy[x][y] & 1;
                    }
                }
                live -= copy[i][j] & 1;
                if ((copy[i][j] & 1) == 1 && (live == 2 || live == 3)) board[i][j] |= 2;
                if ((copy[i][j] & 1) == 0 && live == 3) board[i][j] |= 2;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};