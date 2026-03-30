// Construct a binary tree from given preorder and inorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}


int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}


struct TreeNode* buildTreeHelper(int preorder[], int inorder[], 
                                int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    
    int rootVal = preorder[*preIndex];
    (*preIndex)++;
    struct TreeNode* root = newNode(rootVal);

    
    if (start == end)
        return root;

    
    int inIndex = findIndex(inorder, start, end, rootVal);

    
    root->left = buildTreeHelper(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}


struct TreeNode* buildTree(int preorder[], int inorder[], int size) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, size - 1, &preIndex);
}


void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}


int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[]  = {9, 3, 15, 20, 7};
    int n = 5;

    struct TreeNode* root = buildTree(preorder, inorder, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}