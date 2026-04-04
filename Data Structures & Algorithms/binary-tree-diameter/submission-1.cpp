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
   
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        help(root,dia);
        return dia;
    }
private:
    int help(TreeNode* node, int& dia){
        if(!node)return 0;
        int left = help(node->left,dia);
        int right = help(node->right,dia);
        dia = max(dia,left+right);
        return 1+max(left,right);
    }
    

};
