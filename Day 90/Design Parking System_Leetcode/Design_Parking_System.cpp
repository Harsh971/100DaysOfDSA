class Solution {
 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(begin(cuts), end(cuts));

    // dp[i][j] := minCost(cuts[i..j])
    dp.resize(cuts.size(), vector<int>(cuts.size()));
    return minCost(cuts, 0, cuts.size() - 1);
  }

 private:class ParkingSystem {
 public:
  ParkingSystem(int big, int medium, int small) {
    count = {big, medium, small};
  }

  bool addCar(int carType) {
    return count[carType - 1]-- > 0;
  }

 private:
  vector<int> count;
};
