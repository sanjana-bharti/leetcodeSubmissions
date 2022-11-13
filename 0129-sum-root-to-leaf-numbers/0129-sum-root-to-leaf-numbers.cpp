/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long int sum=0;
    int sumNumbers(TreeNode* root) 
    {
        helper(root,0);
        return sum;
    }
    void helper(TreeNode* root,long long int temp)
    {
        if(root==NULL)
            return ;
        long long int curr=temp;
        curr=curr*10+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum+=curr;
            return ;
        }
        helper(root->left,curr);
        helper(root->right,curr);
        return ;
    }
};