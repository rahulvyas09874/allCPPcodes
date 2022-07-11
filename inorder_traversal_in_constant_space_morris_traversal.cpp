vector<int>inorder_using_morris(TreeNode*root){
    vector<int>ans;
    TreeNode*curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode*temp=curr->left;
            while(temp->right and temp->right!=curr){   // finding inorder successor
                temp=temp->right;
            }
            if(temp->right==nullptr){
                temp->right=curr;
                curr=curr->left;
            }
            else{
                 temp->right=nullptr;
                 ans.push_back(curr->val);
                 curr=curr->right;
            }
        }
    }
    return ans;

}