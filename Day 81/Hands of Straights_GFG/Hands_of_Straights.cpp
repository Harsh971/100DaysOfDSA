class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        multiset<int> ms;
        
        for(auto i : hand){
            ms.insert(i);
        }
        
        while(ms.size()){
            int item = *ms.begin();
            
            for(int i = 0; i < groupSize; i++){
                if(ms.count(item + i) == 0){
                    return 0;
                }
                
                ms.erase(ms.find(item + i)); //ms.erase(item + 1) this wont work
            }
        }
        
        return 1;
    }
};