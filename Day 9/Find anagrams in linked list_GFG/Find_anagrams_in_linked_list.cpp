class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<int> original(26,0), current(26,0);
        for(auto i:s)
            ++original[i-'a'];
            
        Node *left, *right;
        left = right = head;
        
        vector<Node*> ans;
        bool take = 1;
        
        while(left != nullptr and right != nullptr) {
            if(take and right != nullptr)
                ++current[(right -> data) - 'a'];
            take = 0;
            
            int status = 1;
            for(int i=0; i<26; i++) {
                if(current[i] > original[i]) {
                    status = -1;
                    break;
                }
                if(current[i] < original[i]) {
                    status = 0;
                    break;
                }
            }
            
            if(status == 1) {
                ans.push_back(left);
                right = right -> next;
                left = right;
                take = 1;
                for(int i=0; i<26; i++)
                    current[i] = 0;
            }
            else if(status == -1) {
                --current[(left -> data) - 'a'];
                if(left == right)
                    right = right -> next, take = 1;
                left = left -> next;
            }
            else {
                right = right -> next;
                take = 1;
            }
        }
        for(int i=0; i<ans.size(); i++) {
            Node *current = ans[i];
            for(int j=0; j<s.size()-1; j++)
                current = current -> next;
            current -> next = nullptr;
        }
        return ans;
    }
};