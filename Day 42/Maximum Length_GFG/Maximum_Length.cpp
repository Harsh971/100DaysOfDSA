class Solution {
public:
    int solve(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        
        int nax = max({a, b, c});
        int sum = a + b + c - nax;
        
        return (nax <= sum * 2) ? a + b + c : -1;
    }
};