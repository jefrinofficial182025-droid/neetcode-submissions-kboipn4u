class Solution {
public:

    void dfs(int i, int j, int r, int c, vector<vector<int>>& grid, int &area) {
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != 1) return;

        grid[i][j] = 0;
        area++;

        dfs(i + 1, j, r, c, grid, area);
        dfs(i - 1, j, r, c, grid, area);
        dfs(i, j + 1, r, c, grid, area);
        dfs(i, j - 1, r, c, grid, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int maxarea = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, r, c, grid, area);

                    if (area > maxarea) {
                        maxarea = area;
                    }
                }
            }
        }

        return maxarea;
    }
};