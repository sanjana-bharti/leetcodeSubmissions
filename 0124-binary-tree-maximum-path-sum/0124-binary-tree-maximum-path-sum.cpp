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
    long long int ans=INT_MIN;
    int maxPathSum(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        helper(root);
        return ans;
    }
    long long int helper(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
            long long int left=helper(root->left);
            long long int right=helper(root->right);
            long long int temp=max((long long int)(root->val),(long long int)(root->val)+max(left,right));
            long long int res=max(temp,(long long int)(root->val)+left+right);
             ans=max(ans,res);
            return temp;
        
    }
};