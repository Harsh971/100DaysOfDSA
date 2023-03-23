class Solution{
public:
    Node* search(Node* root, int target, int &sum1)
    {
        if(root==NULL)return NULL;
        
        
        sum1+=root->data;
        if(root->data==target)
        {
            return root;
        }
        if(target>root->data)
        {
            return search(root->right,target, sum1);
        }
        else
        {
            return search(root->left,target,sum1);
        }
    }
    
    int leafNodes(Node* root)
    {
        if(root->left==NULL and root->right==NULL)
        {
            return root->data;
        }
        int mn=INT_MAX;
        if(root->left)
        {
            mn=min(mn,leafNodes(root->left));
        }
        if(root->right)
        {
            mn=min(mn,leafNodes(root->right));
        }
        
        return mn+root->data;
    }
    
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int sum1=0;
        Node* targetNode=search(root, target,sum1);
        if(targetNode==NULL)return -1;
        
        int sum2=leafNodes(targetNode);
        
        return sum1-sum2;
        
    }
};