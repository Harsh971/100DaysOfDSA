// Java Solution

class Solution {
    public int mod = 1000000007;
    public void multiply(int[][] a, int[][] b) {
        int mul[][] = new int[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    long temp = ((long)a[i][k] * b[k][j]) % mod;
                    mul[i][j] += temp;
                    mul[i][j] %= mod;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = mul[i][j];
            }
        }
    }
    public int power(int[][] mat, long N) {
        int M[][] = {{1, 1, 0}, {1, 0, 0}, {0, 1, 0}};
        if (N == 1) {
            return (mat[0][0] + mat[0][1]) % mod;
        }
        power(mat, N / 2);
        multiply(mat, mat);
        if (N % 2 != 0) {
            multiply(mat, M);
        }
        return (mat[0][0] + mat[0][1]) % mod;
    }
    int countStrings(long N) {
        int[][] mat = {{1, 1, 0}, {1, 0, 0}, {0, 1, 0}};
        if (N == 2) return 3;
        if (N == 1) return 2;
        return power(mat, N);
    }
}