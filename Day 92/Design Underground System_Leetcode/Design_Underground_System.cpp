class MyHashSet {
 public:
  /** Initialize your data structure here. */
  MyHashSet() : set(1000001) {}

  void add(int key) {
    set[key] = true;
  }

  void remove(int key) {
    set[key] = false;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    return set[key];
  }struct CheckIn {
  string stationName;
  int time;
};

struct CheckOut {
  int numTrips;
  int totalTime;
};

class UndergroundSystem {
 public:
  void checkIn(int id, string stationName, int t) {
    checkIns[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    const auto [startStation, startTime] = checkIns[id];
    checkIns.erase(id);
    const string& route = startStation + "->" + stationName;
    ++checkOuts[route].numTrips;
    checkOuts[route].totalTime += t - startTime;
  }

  double getAverageTime(string startStation, string endStation) {
    const auto& [numTrips, totalTime] =
        checkOuts[startStation + "->" + endStation];
    return totalTime / (double)numTrips;
  }

 private:
  unordered_map<int, CheckIn> checkIns;       // {id: (stationName, time)}
  unordered_map<string, CheckOut> checkOuts;  // {route: (numTrips, totalTime)}
};
