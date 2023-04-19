class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int current = 0;
        
        for(auto i : S){
            if(i == '1'){
                current = -X;
                continue;
            }
            
            ++current;
            
            if(current > X)
                return 0;
        }
        
        return current <= 0;
    }
};