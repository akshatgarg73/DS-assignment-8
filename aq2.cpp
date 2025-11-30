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

Node* insertNode(Node *root, int x) {
    if (root == NULL) {
        root = createNode(x);
        return root;
    }
    if (x < root->data)
        root->left = insertNode(root->left, x);
    else if (x > root->data)
        root->right = insertNode(root->right, x);
    return root;
}

Node* searchRec(Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}

Node* searchIter(Node *root, int key) {
    Node *curr = root;
    while (curr != NULL && curr->data != key) {
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr;
}

Node* findMax(Node *root) {
    if (root == NULL) return NULL;
    Node *curr = root;
    while (curr->right != NULL)
        curr = curr->right;
    return curr;
}

Node* findMin(Node *root) {
    if (root == NULL) return NULL;
    Node *curr = root;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node* inorderSuccessor(Node *root, int key) {
    Node *curr = root;
    Node *succ = NULL;
    while (curr != NULL && curr->data != key) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (curr == NULL) return NULL;
    if (curr->right != NULL)
        return findMin(curr->right);
    return succ;
}

Node* inorderPredecessor(Node *root, int key) {
    Node *curr = root;
    Node *pred = NULL;
    while (curr != NULL && curr->data != key) {
        if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    if (curr == NULL) return NULL;
    if (curr->left != NULL)
        return findMax(curr->left);
    return pred;
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    int n, x, key;
    cout << "How many nodes? ";
    cin >> n;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertNode(root, x);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "Enter key to search: ";
    cin >> key;

    Node *r1 = searchRec(root, key);
    if (r1 != NULL) cout << "Found (recursive)." << endl;
    else cout << "Not found (recursive)." << endl;

    Node *r2 = searchIter(root, key);
    if (r2 != NULL) cout << "Found (iterative)." << endl;
    else cout << "Not found (iterative)." << endl;

    Node *mn = findMin(root);
    Node *mx = findMax(root);
    if (mn != NULL) cout << "Minimum element: " << mn->data << endl;
    if (mx != NULL) cout << "Maximum element: " << mx->data << endl;

    Node *succ = inorderSuccessor(root, key);
    if (succ != NULL) cout << "Inorder successor of " << key << " is: " << succ->data << endl;
    else cout << "Inorder successor does not exist or key not found." << endl;

    Node *pred = inorderPredecessor(root, key);
    if (pred != NULL) cout << "Inorder predecessor of " << key << " is: " << pred->data << endl;
    else cout << "Inorder predecessor does not exist or key not found." << endl;

    return 0;
}
