#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

typedef struct Node {
    int data;
    enum Color color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct RedBlackTree {
    Node* root;
} RedBlackTree;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void leftRotate(RedBlackTree* tree, Node* node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;
    if (rightChild->left != NULL) {
        rightChild->left->parent = node;
    }
    rightChild->parent = node->parent;
    if (node->parent == NULL) {
        tree->root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }
    rightChild->left = node;
    node->parent = rightChild;
}

void rightRotate(RedBlackTree* tree, Node* node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;
    if (leftChild->right != NULL) {
        leftChild->right->parent = node;
    }
    leftChild->parent = node->parent;
    if (node->parent == NULL) {
        tree->root = leftChild;
    } else if (node == node->parent->right) {
        node->parent->right = leftChild;
    } else {
        node->parent->left = leftChild;
    }
    leftChild->right = node;
    node->parent = leftChild;
}

void insertFixup(RedBlackTree* tree, Node* node) {
    while (node != tree->root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(tree, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(tree, node->parent->parent);
            }
        } else {
            Node* uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(tree, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

void insert(RedBlackTree* tree, int data) {
    Node* newNode = createNode(data);
    Node* parent = NULL;
    Node* current = tree->root;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (parent == NULL) {
        tree->root = newNode;
    } else if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    insertFixup(tree, newNode);
}

void inOrderTraversal(Node* node) {
    if (node == NULL) return;
    inOrderTraversal(node->left);
    printf("%c (%s) ", node->data, (node->color == RED) ? "RED" : "BLACK");
    inOrderTraversal(node->right);
}

int main() {
    RedBlackTree tree;
    tree.root = NULL;

    char values[] = {'F','G', 'S', 'Q', 'K', 'C', 'L', 'H', 'T', 'V', 'W', 'M','R','N','P','A','B','X','Y','D','Z','E'};
    int num_values = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < num_values; i++) {
        insert(&tree, values[i]);
    }

    printf("In-order traversal of the Red-Black Tree:\n");
    inOrderTraversal(tree.root);
    printf("\n");

    return 0;
}
