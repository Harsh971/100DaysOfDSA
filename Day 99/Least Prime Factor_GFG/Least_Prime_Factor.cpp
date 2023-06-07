class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans(n + 1);
        
        for(int i = 0; i < n + 1; i++)
            ans[i] = i;
            
        for(int i = 2; i * i < n + 1; i++){
            if(ans[i] == i){
                for(int j = i + i; j < n + 1; j += i)
                    ans[j] = min(ans[j], i);
            }
        }
        
        return ans;
    }
};