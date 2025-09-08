#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
};

void reverseInOrderTraversal(struct TreeNode* node, int* sum) {
    if (node == NULL) {
        return;
    }
    
    reverseInOrderTraversal(node->right, sum);
    
    *sum = *sum + node->val;
    node->val = *sum;
    
    reverseInOrderTraversal(node->left, sum);
}


struct TreeNode* bstToGst(struct TreeNode* root) {
    int sum = 0;
    
    reverseInOrderTraversal(root, &sum);
    
    return root;
}