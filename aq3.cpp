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

// (a) INSERT, no duplicates
Node* insertNode(Node *root, int x) {
    if (root == NULL) {
        root = createNode(x);
        return root;
    }
    if (x < root->data)
        root->left = insertNode(root->left, x);
    else if (x > root->data)
        root->right = insertNode(root->right, x);
    // if x == root->data do nothing (no duplicates)
    return root;
}

// helper: minimum node in a subtree (used in delete)
Node* findMin(Node *root) {
    if (root == NULL) return NULL;
    Node *cur = root;
    while (cur->left != NULL)
        cur = cur->left;
    return cur;
}

// (b) DELETE an existing element
Node* deleteNode(Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // node found
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// (c) maximum depth (height)
int maxDepth(Node *root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

// (d) minimum depth
int minDepth(Node *root) {
    if (root == NULL)
        return 0;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (root->left == NULL && root->right != NULL)
        return rightDepth + 1;
    if (root->right == NULL && root->left != NULL)
        return leftDepth + 1;

    if (leftDepth < rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

// inorder just to see tree
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    int n, x;
    cout << "How many elements to insert? ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertNode(root, x);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Enter value to delete: ";
    cin >> x;
    root = deleteNode(root, x);

    cout << "Inorder after delete: ";
    inorder(root);
    cout << endl;

    cout << "Maximum depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum depth of BST: " << minDepth(root) << endl;

    return 0;
}
