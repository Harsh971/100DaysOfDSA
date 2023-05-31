class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> f;
        
        for(int i = 0; i < n; i++)
            ++f[arr[i]];
            
        int minFrequency, ans = -1;
        minFrequency = 1e6;
        
        for(auto it : f){
            if(it.second < minFrequency){
                minFrequency = it.second;
                ans = it.first;
            }
            else if(it.second == minFrequency){
                ans = max(ans, it.first);
            }
        }
        
        return ans;
    }
};