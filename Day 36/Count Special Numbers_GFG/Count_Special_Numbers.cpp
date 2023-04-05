class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        
        int mx=INT_MIN;
        for(int i=0;i<N; i++)
        {
            mx=max(mx,arr[i]);
        }
        vector<int>temp(mx+1,0);
        
        for(int i=0;i<N; i++)
        {
            if(temp[arr[i]]<=1)
            {
                for(int j=arr[i]; j<=mx; j+=arr[i])
                {
                    temp[j]++;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<N; i++)
        {
            if(temp[arr[i]]>1)
            {
                count++;
            }
            
        }
        
        return count;
    }
};