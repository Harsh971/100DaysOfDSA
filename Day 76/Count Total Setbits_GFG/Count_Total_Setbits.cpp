class Solution {
  public:
    long long countBits(long long N) {
        long long ans = 0;
        ++N;
        
        for(long long i = 0; i < 32; i++){
            long long x = N / (1LL << (i + 1));
            x = x * (1 << i);
            ans += x;
            
            if(i < 31){
                long long y = N % (1LL << (i + 1));
                y = max(0LL, y - (1LL << i));
                ans += y;
            }
        }
        
        return ans;
    }
};