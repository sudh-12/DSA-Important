class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& visi,
             vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        visi[row][col] = 1;
        mat[row][col] = 'N';

        int dir[] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < 4; ++i) {
            int nrow = row + dir[i];
            int ncol = col + dir[i + 1];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visi[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visi, mat);
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visi(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 'O' &&
                    (i == 0 || j == 0 || i == n - 1 || j == m - 1) &&
                    !visi[i][j]) {
                    dfs(i, j, visi, mat);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
                else if (mat[i][j] == 'N')
                    mat[i][j] = 'O';
            }
        }
    }
};