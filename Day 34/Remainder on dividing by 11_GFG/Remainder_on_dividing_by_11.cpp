class Solution
{

public:
    int xmod11(string x)
    {
       // code her
       int odd=0;
       int even=0;
       
       for(int i=0;i<x.size(); i+=2)
       {
           even+=(x[i]-'0');
       }
       
       for(int i=1;i<x.size(); i+=2)
       {
           odd+=(x[i]-'0');
       }
        
        int rem=(odd-even)%11;
        
        if(rem>=0)return rem;
        
        return rem+11;
        
    }
};