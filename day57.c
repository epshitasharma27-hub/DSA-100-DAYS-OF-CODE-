// Convert a binary tree into its mirror image by swapping left and right children at every node.
#include <stdio.h>
#include <stdlib.h>

// Define structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Mirror function (recursive)
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;

    // Swap left and right
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main function
int main() {
    // Creating tree manually
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder of Original Tree:\n");
    inorder(root);

    // Convert to mirror
    invertTree(root);

    printf("\nInorder of Mirror Tree:\n");
    inorder(root);

    return 0;
}