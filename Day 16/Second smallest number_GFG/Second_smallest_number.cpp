class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(S >= D*9)
        {
            return "-1";
        }
        string ans="";
        S-=1;
        for(int i=0; i<D-1; i++)
        {
            if(S>9)
            {
                ans += (9+'0');
                S-=9;
            }
            else
            {
                ans += (S+'0');
                S=0;
            }
        }
        ans += (S+1)+'0';
        reverse(ans.begin(),ans.end());
        
        int index = D-1;
        
        for(int i=D-1; i>=0; i--)
        {
            if(ans[i]=='9')
            {
                index=i;
            }
            else
            {
                break;
            }
        }
        ans[index] -= 1;
        ans[index-1] += 1;
        
        return ans;
    }
};