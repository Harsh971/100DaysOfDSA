class Solution {
    public:
    void dfs(vector<vector<int>>& matrix, int r, int c) {
        if (r < 0 || r == matrix.size() || c < 0 || c == matrix[0].size() || matrix[r][c] == 0) return;
        matrix[r][c] = 0;
        dfs(matrix, r + 1, c);
        dfs(matrix, r - 1, c);
        dfs(matrix, r, c + 1);
        dfs(matrix, r, c - 1);
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
       
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                if (r == 0 || r == N - 1 || c == 0 || c == M - 1) {
                    dfs(matrix, r, c);
                }
            }    
        }     
        int res = 0;
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                if (matrix[r][c] == 1) {
                    res++;
                    dfs(matrix, r, c);
                }
            }
        }
        return res;
    }
};