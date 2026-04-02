// Check whether a given binary tree satisfies the Min-Heap property.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to count total nodes
int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is complete
int isComplete(struct TreeNode* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check heap property
int isMinHeap(struct TreeNode* root) {
    if (root == NULL)
        return 1;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL)
        return (root->val <= root->left->val) &&
               isMinHeap(root->left);

    // Both children
    return (root->val <= root->left->val &&
            root->val <= root->right->val) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

// Main function to check Min Heap
int checkMinHeap(struct TreeNode* root) {
    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) &&
        isMinHeap(root))
        return 1;

    return 0;
}