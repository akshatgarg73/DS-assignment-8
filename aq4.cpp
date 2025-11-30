#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* insertBST(Node *root, int x) {
    if (root == NULL) {
        root = createNode(x);
        return root;
    }
    if (x < root->data)
        root->left = insertBST(root->left, x);
    else if (x > root->data)
        root->right = insertBST(root->right, x);
    return root;
}

bool isBSTUtil(Node *root, int minVal, int maxVal) {
    if (root == NULL)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node *root) {
    return isBSTUtil(root, -1000000000, 1000000000);
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    int n, x;
    cout << "How many nodes to insert (BST style)? ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertBST(root, x);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    if (isBST(root))
        cout << "Given binary tree IS a BST.\n";
    else
        cout << "Given binary tree is NOT a BST.\n";

    return 0;
}
