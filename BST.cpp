#include <iostream>
using namespace std;
struct BSTNode {
    int data;
    BSTNode *left, *right;
};
BSTNode* insert(BSTNode* root, int data) {
    if (root == NULL) {
        BSTNode* newNode = new BSTNode();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}
void inorder(BSTNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    BSTNode* root = NULL;
    root = insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 8);
    insert(root, 12);
    insert(root, 17);
    insert(root, 25);
    cout << "Inorder Traversal (Sorted Output): " << endl;
    inorder(root);
    cout << endl;
    return 0;
}