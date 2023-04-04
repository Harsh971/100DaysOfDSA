int minSteps(string str) {
    // Write your code here.
    int a=0;
    int b=0;
    
    if(str[0]=='a')
    {
        a++;
    }
    else
    {
        b++;
    }
    for(int i=1;i<str.size(); i++)
    {
        if(str[i-1]=='a' and str[i]=='b')
        {
            b++;
        }
        
        if(str[i-1]=='b' and str[i]=='a')
        {
            a++;
        }
    }
    
    return min(a,b)+1;
    
}