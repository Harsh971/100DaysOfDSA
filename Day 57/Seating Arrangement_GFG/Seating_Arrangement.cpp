class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        int seat = 0;

        while(seat < m and n){
            if(seat + 1 < m and seats[seat + 1] == 1){
                seat += 3;
                continue;
            }
            
            if(seats[seat] == 1){
                seat += 2;
                continue;
            }
            
            if(seat > 0 and seats[seat - 1] == 1){
                ++seat;
                continue;
            }
            
            --n;
            seat += 2;
        }
        
        return n == 0;
    }
};
