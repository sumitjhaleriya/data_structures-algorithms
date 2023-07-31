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
void Search1(Node *root,int t){
    if(root == NULL){
        cout << "Not in tree"
             << " ";
    }

    if(t > root->data ){
        root = root->right;
        Search1(root, t);
    }
    else if(t< root->data){
        root = root->left;
        Search1(root, t);
    }
    else if (t==root->data){
        cout <<"Find"<<endl;
    }
}

Node * Search2(Node *root,int t){
    while(root != NULL && root->data !=t ){
        root = t < root->data ? root->left : root->right;
    }
    return root;
}
int main()
{
    struct Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    // Search1(root, 1);
    // cout << Search2(root, 10)->data;
    return 0;
}