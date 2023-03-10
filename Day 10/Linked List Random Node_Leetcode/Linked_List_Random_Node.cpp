class Solution {
 public:
  
  Solution(ListNode* head) : head(head) {}

    int getRandom() {
    int ans = -1;
    int i = 1;

    for (ListNode* curr = head; curr; curr = curr->next, ++i)
      if (rand() % i == 0)
        ans = curr->val;

    return ans;
  }

 private:
  ListNode* head;
};
