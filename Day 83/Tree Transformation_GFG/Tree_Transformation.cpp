class Solution {
    public:
    int solve(int n, vector<int> p){
        vector<int> out(n, 0);
        
        for(int i = 1; i < n; i++){
            ++out[p[i]];
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            ans += out[i] == 0;
            
        if(out[0] == 1)
            ++ans;
            
        return max(n - 1 - ans, 0);
    }
};