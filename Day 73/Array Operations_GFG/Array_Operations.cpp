class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        bool f = false;
        int cntZero = count(arr.begin(), arr.end(), 0);
        if(cntZero == 0)
            return -1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if( f == false && arr[i] != 0){
                cnt++;
                f = true;
            }
            else if( arr[i] == 0){
                f = false;
            }
        }
        return cnt;
    }
};