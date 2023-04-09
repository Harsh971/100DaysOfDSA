class Solution {
  public:
    const int mod = 1e9 + 7;

    long long nCr(int n, int r, int p) {
        if (r == 0 || r == n) {
            return 1;
        }
        long long fact[n+1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % p;
        }
        long long invR = modInv(fact[r], p);
        long long invNR = modInv(fact[n-r], p);
    
        return ((fact[n] * invR) % p * invNR) % p;
    }
    
    long long modInv(long long a, long long p) {
        long long m0 = p;
        long long y = 0, x = 1;

        if (p == 1) {
            return 0;
        }
        while (a > 1) {
            long long q = a / p;
            long long t = p;

            p = a % p;
            a = t;
            t = y;

            y = x - q * y;
            x = t;
        }
        if (x < 0) {
            x += m0;
        }
        return x;
    }


    int bestNumbers(int n, int a, int b, int c, int d) {
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            int sum = i*a + (n-i)*b;
            bool good = true;
            
            while (sum > 0) {
                if (sum % 10 != c && sum % 10 != d) {
                    good = false;
                    break;
                }
                sum /= 10;
            }
            
            if (good) {
                ans += nCr(n, i, mod);
                ans %= mod;
            }
            }
        return (int)ans;
    }
};