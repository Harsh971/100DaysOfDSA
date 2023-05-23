class Solution{
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        Node * head = nullptr;
        int pos = size - 1;
        int index = 0;
        
        function<void(Node* &)> construct = [&](Node * &current) {
            if(index == 0){
                current = new Node(pre[index]);
            }
            
            if(current -> data != preMirror[pos]){
                current -> left = new Node(pre[++index]);
                construct(current -> left);
                
                current -> right = new Node(pre[++index]);
                construct(current -> right);
            }
            
            --pos;
        };
        
        construct(head);
        
        return head;
    }
};