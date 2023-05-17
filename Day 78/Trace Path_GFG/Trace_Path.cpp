class Solution{
public:
    int isPossible(int n, int m, string s){
        int dx, dy;
        dx = dy = 0;
        
        int maxx, minx, maxy, miny;
        maxx = maxy = minx = miny = 0;
        
        for(auto i : s){
            if(i == 'L'){
                --dy;
            }
            else if(i == 'R'){
                ++dy;
            }
            else if(i == 'D'){
                --dx;
            }
            else{
                ++dx;
            }
            
            maxx = max(dx, maxx);
            maxy = max(dy, maxy);
            
            minx = min(dx, minx);
            miny = min(dy, miny);
            
            if(maxx - minx >= n or maxy - miny >= m)
                return 0;
        }
        
        return 1;
    }
};