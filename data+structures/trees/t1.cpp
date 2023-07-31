#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node *n)
{
    if (n == NULL)
        return;
    cout << n->data << endl;
    preorder(n->left);
    preorder(n->right);
}

void postorder(Node *n)
{
    if (n == NULL)
        return;
    postorder(n->left);
    postorder(n->right);
    cout << n->data << endl;
}

void inorder(Node *n)
{
    if (n == NULL)
        return;
    inorder(n->left);
    cout << n->data << endl;
    inorder(n->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    preorder(root);
    //This code works well
    return 0;
}