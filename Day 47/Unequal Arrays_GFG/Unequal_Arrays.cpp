class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        vector<int> odda, oddb, evena, evenb;
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        for(int i = 0; i < N; i++){
            if(A[i] & 1)
                odda.push_back(A[i]);
            else
                evena.push_back(A[i]);
                
            if(B[i] & 1)
                oddb.push_back(B[i]);
            else
                evenb.push_back(B[i]);
        }
        
        
        if(odda.size() != oddb.size())
            return -1;
            
        int op, pending;
        op = pending = 0;
        
        
        function<void(vector<int>, vector<int>)> dowork = [&](vector<int> a, vector<int> b) {
            for(int i = 0; i < a.size(); i++){
                if(a[i] < b[i]){
                    int dx = (a[i] - b[i]) / 2; // dx will be negative
                    
                    int free = max(pending, dx); // dx is the amount that i want to increase
                    free = min(0, free);
                    pending -= free;
                    dx -= free;
                    
                    op += abs(dx);
                    pending += abs(dx);
                }
                else if(a[i] > b[i]){
                    int dx = (a[i] - b[i]) / 2; // dx will be positive
                    
                    int free = min(pending, dx);
                    free = max(0, free);
                    pending -= free;
                    dx -= free;
                    
                    op += dx;
                    pending -= dx;
                }
            }
        };
        
        dowork(odda, oddb);
        dowork(evena, evenb);
        
        return ((pending == 0) ? op : -1);
    }
};