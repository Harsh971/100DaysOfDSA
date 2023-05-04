class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        sort(ranges.begin(), ranges.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        
        vector<int> post(n);
        post[n - 1] = ranges[n - 1][2];
        
        for(int i = n - 2; i > -1; i--)
            post[i] = max(post[i + 1], ranges[i][2]);
            
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int l = i;
            int h = n;
            
            while(l < h - 1){
                int mid = l + (h - l) / 2;
                
                if(ranges[mid][0] >= ranges[i][1])
                    h = mid;
                else
                    l = mid;
            }
            
            int cur = 0;
            if(h < n)
                cur = post[h];
                
            ans = max(ans, ranges[i][2] + cur);
        }
        
        return ans;
    }
};
