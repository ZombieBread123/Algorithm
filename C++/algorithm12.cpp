#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;
};
void insert(struct node** root, int data) {
    if (*root == nullptr) {
        *root = new node();
        (*root)->data = data;
        (*root)->left = nullptr;
        (*root)->right = nullptr;
    } else {
        if (data <= (*root)->data) {
            insert(&((*root)->left), data);
        } else {
            insert(&((*root)->right), data);
        }
    }
}
void preOrder(struct node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(struct node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int size(struct node* root) {
    if (root == nullptr) return 0;
    return 1 + size(root->left) + size(root->right);
}
int height(struct node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}
int sumOfWeight(struct node* root) {
    if (root == nullptr) return 0;
    return root->data + sumOfWeight(root->left) + sumOfWeight(root->right);
}
int maxPathWeight(struct node* root) {
    if (root == nullptr) return 0;
    int leftMax = maxPathWeight(root->left);
    int rightMax = maxPathWeight(root->right);
    return root->data + max(leftMax, rightMax);
}
void mirror(struct node** root) {
    if (*root == nullptr) return;
    swap((*root)->left, (*root)->right);
    mirror(&((*root)->left));
    mirror(&((*root)->right));
}
void destruct(struct node** root) {
    if (*root == nullptr) return;
    destruct(&((*root)->left));
    destruct(&((*root)->right));
    delete *root;
    *root = nullptr;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        struct node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            insert(&root, data);
        }
        cout <<size(root) << endl;
        cout <<height(root)-1 << endl;
        cout <<sumOfWeight(root) << endl;
        cout <<maxPathWeight(root) << endl;
        mirror(&root);
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
        destruct(&root);
        if(root == nullptr) cout << "0" << endl;
        else cout << "1" << endl;
        destruct(&root);
    }
    return 0;
}
