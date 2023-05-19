class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end());
        
        vector<int> ans(q);
        for(int p = 0; p < q; p++){
            int current = range[0][0];
            int pos = 1;
            
            for(int i = 0; i < n; i++){
                int need = queries[p] - pos;
                
                if(need and range[i][0] > current){
                    --need;
                    ++pos;
                    current = range[i][0];
                }
                
                int cango = range[i][1] - current;
                int change = min(cango, need);
                change = max(0, change);
                
                pos += change;
                current += change;
            }
            
            
            ans[p] = (pos == queries[p]) ? current : -1;
        }
        
        return ans;
    } 
};