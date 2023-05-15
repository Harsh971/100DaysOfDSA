class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *x=head, *y=head, *t=head;

        // Until we reach k-th node from beginning
        while(k>1){
            x = x->next;
            t = t->next;
            k--;
        }

        // Until pointer t reach last need 
        while(t->next){
            y=y->next;
            t=t->next;
        }

        // Swap values at both the nodes
        int temp = x->val;
        x->val = y->val;
        y->val = temp;

        return head;
    }
};