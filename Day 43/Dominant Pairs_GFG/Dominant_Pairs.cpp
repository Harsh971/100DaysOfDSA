class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        map<int,int> mp;
        
        for(int i = 0; i < n / 2; i++)
            mp[arr[i]]++;
            
        auto ptr = mp.end();
        --ptr;
        int current = 0;
        
        while(ptr != mp.begin()){
            (*ptr).second += current;
            current = (*ptr).second;
            --ptr;
        }
        
        (*ptr).second += current;
        
        int ans = 0;
        
        for(int i = n / 2; i < n; i++){
            auto ptr = mp.lower_bound(5 * arr[i]);
            
            if(ptr != mp.end())
                ans += (*ptr).second;
        }
        
        return ans;
    }  
};