class Solution {
public:
    double average(vector<int>& salary) {
        int total = 0;
        int mi = numeric_limits<int>::max(), ma = numeric_limits<int>::min();
        for (const auto& s : salary) {
            total += s;
            mi = min(mi, s), ma = max(ma, s);
        }
        return double(total - mi - ma) / (salary.size() - 2);
    }
};