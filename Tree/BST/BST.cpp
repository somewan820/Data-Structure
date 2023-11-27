/*Binary Search Tree*/
/*
A BST is which for each node,value of all the nodes in left subtree is
lesser or equal and value of all the nodes in right subtree is greater
*/
#include <iostream>
#include <queue>

struct BstNode {
    int data;
    BstNode* left = NULL; //to store address of left child
    BstNode* right = NULL; //to store address of right child
};

BstNode* GetNewNode(int data) {
    BstNode* Node = new BstNode;
    Node->data = data;
    return Node;
}

BstNode* Insert(BstNode* root,int data) {
    if (root == NULL) { //empty tree
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root,int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

BstNode* FindMin(BstNode* root) {
    if (root == NULL) {
        std::cout << "Error:Tree is empty" << std::endl; //the condition of empty tree
        return NULL;
    }
    else if (root->left == NULL) {
        return root;
    }
    return FindMin(root->left);
}

BstNode* FindMax(BstNode* root) {
    if (root == NULL) {
        std::cout << "Error:Tree is empty" << std::endl; //the condition of empty tree
        return NULL;
    }
    else if (root->right == NULL) {
        return root;
    }
    return FindMax(root->right);
}

int FindHeight(BstNode* root) {
    if (root == NULL) return -1;
    int LeftHeight = FindHeight(root->left);
    int RightHeight = FindHeight(root->right);
    return std::max(LeftHeight, RightHeight)+1;
}

void LevelOrder(BstNode* root) { // Stratum Traversal
    if (root == NULL) return;
    std::queue<BstNode*> Q;
    while (!Q.empty()) {
        BstNode* current = Q.front();
        std::cout << current->data << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop(); //removing the front element
    }
}

void PreOrder(BstNode* root) {
    if (root == NULL) return;
    std::cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BstNode* root) {
    if (root == NULL) return;
    InOrder(root->left);
    std::cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(BstNode* root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->data << " ";
}

bool IsBSTUtil(BstNode* root, int MinValue, int MaxValue) {
    if (root == NULL) return true;
    if (root->data < MaxValue && root->data >= MinValue
    && IsBSTUtil(root->left, MinValue, root->data)
    && IsBSTUtil(root->right, root->data, MaxValue))
        return true;
    else return false;
}

bool IsBinarySearchTree(BstNode* root) {
    return IsBSTUtil(root, INT_MIN, INT_MAX);
}

//Delete a node from BST
BstNode* Delete(BstNode* root, int data) {
    if (root == NULL) return NULL;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {
        //case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        //case 2: One child
        else if (root->left == NULL) {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: Two children
        else {
            BstNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}