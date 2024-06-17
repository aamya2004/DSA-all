/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void solve(TreeNode* root, vector<int> &ino, vector<int> &pre,vector<int> &post){
    if(root == NULL){
        return;
    }
    pre.push_back(root->data);
    solve(root->left,ino,pre,post);
    ino.push_back(root->data);  
    solve(root->right,ino,pre,post);
    post.push_back(root->data);


}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    vector<int>pre,ino,post;
    solve(root,ino,pre,post);
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;

}