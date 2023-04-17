class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, [](Job &a,Job &b){
            if(a.profit == b.profit)
                return a.dead < b.dead;
            return a.profit > b.profit;
        });
        
        int ds[n + 1];
        memset(ds, -1, sizeof(ds));
        
        function<int(int)> find = [&](int a) -> int {
            if(ds[a] < 0)
                return a;
            return ds[a] = find(ds[a]);
        };
        
        function<void(int, int)> merge = [&](int a, int b){
            a = find(a);
            b = find(b);
            
            if(a > b)
                swap(a, b);
                
            if(a == b)
                return;
                
            ds[a] += ds[b];
            ds[b] = a;
        };
        
        vector<int> ans(2, 0);
        
        for(int i = 0; i < n; i++){
            int x = find(arr[i].dead);
            
            if(x == 0)
                continue;
                
            merge(x, x - 1);
            
            ans[1] += arr[i].profit;
            ans[0]++;
        }
        
        return ans;
    } 
};