class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        int ans = 0;
        
        for(int i = 0; i < n / 2; i++)
            ans += arr[i] != arr[n - i - 1];
            
        return (ans + 1) / 2; 
    }
};