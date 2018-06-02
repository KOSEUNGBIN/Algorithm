//
// Created by 고승빈 on 2018. 6. 2..
//

#include <iostream>
using namespace std;

struct Node {
    int data = 0;
    Node* parent = NULL;
    Node* left = NULL;
    Node* right = NULL;
};

class UnbalancedTree {
private:
    Node* root = NULL;
public:
    UnbalancedTree();
    void insert(int data);
    void postOrderTraversal(Node* node);
    Node* first();
};

UnbalancedTree::UnbalancedTree() {
}

void UnbalancedTree::insert(int data) {
    if(this->root == NULL) {
        this->root = new Node();
        this->root->data = data;
        return;
    }

    Node* cur = this->root;
    Node* parent = this->root->parent;
    while(cur != NULL) {
        parent = cur;
        if (data > cur->data) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->parent = parent;
    if(parent->data > newNode->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

Node *UnbalancedTree::first() {
    return this->root;
}

void UnbalancedTree::postOrderTraversal(Node* node) {
    if(node == NULL) return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d\n",node->data);
}

int main() {
    int input;
    UnbalancedTree tree;
    while(scanf("%d", &input) != EOF) {
        tree.insert(input);
    }

    tree.postOrderTraversal(tree.first());
    return 0;
}