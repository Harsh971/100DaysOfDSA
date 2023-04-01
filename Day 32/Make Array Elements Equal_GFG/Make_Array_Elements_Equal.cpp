class Solution {
  public:
    long long int minOperations(int N) {
        // Code here
        long long int last=2*(N-1)+1;
        long long mid=(last+1)/2;
        
        if(mid%2==0)return mid*mid/4;
        
        return (mid-1)*(mid+1)/4;
    }
};