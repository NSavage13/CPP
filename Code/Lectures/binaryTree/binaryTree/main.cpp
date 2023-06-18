//
//  main.cpp
//  binaryTree
//
//  Created by Nico Savage on 6/14/23.
//

#include <iostream>

// Structure for a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the binary tree
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to traverse the binary tree in inorder (left-root-right) fashion
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 11);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 6);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    
    
    std::cout << "Inorder traversal of the binary tree: ";
    inorderTraversal(root);
    std::cout << "\n";
    std::cout << root->data << "\n";


    return 0;
}

