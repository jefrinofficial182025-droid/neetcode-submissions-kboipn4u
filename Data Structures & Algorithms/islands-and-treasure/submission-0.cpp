class Solution {
public:
    int dirn[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int q[10000][2];
        int front = 0, rear = 0;

        // push all treasure cells (0)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q[rear][0] = i;
                    q[rear][1] = j;
                    rear++;
                }
            }
        }

        while(front < rear){
            int cr = q[front][0];
            int cc = q[front][1];
            front++;

            for(int i = 0; i < 4; i++){
                int nx = cr + dirn[i][0];
                int ny = cc + dirn[i][1];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == INT_MAX){
                    grid[nx][ny] = grid[cr][cc] + 1;

                    q[rear][0] = nx;
                    q[rear][1] = ny;
                    rear++;
                }
            }
        }
    }
};
