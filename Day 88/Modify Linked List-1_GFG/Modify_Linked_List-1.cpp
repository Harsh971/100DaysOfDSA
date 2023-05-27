class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        Node * slow = head;
        Node * fast = head;
        
        while(fast != nullptr and fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        if(fast != nullptr){
            slow = slow -> next;
        }
        
        if(slow == nullptr)
            return head;
        
        Node * last = slow;
        
        auto reverse = [&last](Node * current, Node * prev) {
            while(current != nullptr){
                last = current;
                Node * next = current -> next;
                current -> next = prev;
                prev = current;
                current = next;
            }
        };
        
        reverse(slow, nullptr);
        
        Node * front = head;
        Node * back = last;
        while(back != nullptr){
            int temp = front -> data;
            
            front -> data = back -> data - front -> data;
            back -> data = temp;
            
            front = front -> next;
            back = back -> next;
        }
        
        reverse(last, nullptr);
        
        return head;
    }
};