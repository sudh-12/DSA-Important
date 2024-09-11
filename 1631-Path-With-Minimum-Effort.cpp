class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> temp(n, vector<int>(m, 1e9));

        temp[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});
        int dir[5] = {0, -1, 0, 1, 0};

        while (!pq.empty()) {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dif = pq.top().first;
            pq.pop();
            for (int i = 0; i < 4; ++i) {
                int nrow = row + dir[i];
                int ncol = col + dir[i + 1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int cd = max(dif, abs(grid[row][col] - grid[nrow][ncol]));

                    if (cd < temp[nrow][ncol]) {
                        temp[nrow][ncol] = cd;
                        pq.push({cd, {nrow, ncol}});
                    }
                }
            }
        }

    return temp[n - 1][m - 1];
}
}
;