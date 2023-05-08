class Solution{
    public:
        int modulo(string s,int m)
        {
            int ans = 0;
            
            reverse(s.begin(), s.end());
            
            int current = 1;
            
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '1'){
                    ans = (ans + current) % m;
                }
                
                current = (current * 2) % m;
            }
            
            return ans;
        }
};