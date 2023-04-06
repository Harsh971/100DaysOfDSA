class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        vector<int> prefix(N + 2, 0), suffix(N + 2, 0);
        
        for(int i = 1; i < N + 1; i++)
            prefix[i] = prefix[i - 1] + A[i - 1];
            
        for(int i = N; i > 0; i--)
            suffix[i] = suffix[i + 1] + A[i - 1];
            
        for(int i = 1; i < N + 1; i++){
            if(prefix[i - 1] == suffix[i + 1]){
                return i;
            }
        }
        
        return -1;
    }
};
