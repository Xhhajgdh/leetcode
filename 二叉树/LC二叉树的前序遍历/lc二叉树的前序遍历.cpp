#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void travel(struct TreeNode* root, int* arr, int* size) {
    if (root != NULL) {
        arr[(*size)++] = root->val;
        travel(root->left, arr, size);
        travel(root->right, arr, size);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    travel(root, arr, returnSize);
    return arr;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* arr = (int*)malloc(100 * sizeof(int));
    struct TreeNode* stk[100];
    int stk_top = -1;

    while (stk_top > -1 || root != NULL) {
        while (root != NULL) {
            arr[(*returnSize)++] = root->val;
            stk[++stk_top] = root;
            root = root->left;
        }
        root = stk[stk_top--];
        root = root->right;
    }
    return arr;
}
