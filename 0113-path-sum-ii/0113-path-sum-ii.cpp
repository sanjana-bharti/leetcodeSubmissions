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
    vector<vector<int>> res;
    void helper(TreeNode* root, int sum,int targetSum,vector<int>& arr)
    {
        if(root==NULL)
            return;
        vector<int> temp;
        temp=arr;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            res.push_back(temp);
            return ;
        }
        else
        {
            if(root->left)
            {
            
             helper(root->left,sum+root->left->val,targetSum,temp);   
               
            }
            if(root->right)
            {
              
             helper(root->right,sum+root->right->val,targetSum,temp);
            }
            
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> arr;
        if(root)
        helper(root,root->val,targetSum,arr);
        return res;
    }
};