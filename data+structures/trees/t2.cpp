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
    if(n->left){
        
    }
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
vector<vector<int>> level_order_traversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.push_back(node->data);
        }

        ans.push_back(level);

    }
    return ans;
}
int maxDepth(struct Node *root)
{
    // we need to find height of a binary tree
    //  post order traversal is happening here 
    
    if (root == NULL)
        return 0;
    int lh = maxDepth(root->left);
    //cout << " lh : " << lh << endl;
    int rh = maxDepth(root->right);
    //cout<<" rh: " << rh << endl;
    return 1 + max(lh, rh);
}
int dfsHeight(struct Node *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(struct Node *root)
{
    return dfsHeight(root) != -1;
}
int Height(struct Node *node, int &diameter)
{

    if (!node)
    {
        return 0;
    }

    int lh = Height(node->left, diameter);
    int rh = Height(node->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(struct Node *root)
{
    int diameter = 0;
    Height(root, diameter);
    return diameter;
}
int tra(struct Node *root, int &m)
{
    if (root == NULL)
        return 0;
    int lh = tra(root->left, m);
    int rh = tra(root->right, m);
    int p = max(lh, rh);
    int maxp = max(m, p);
    return p;
}
int findMaxSum(struct Node *root)
{
    int m = 0;
    return tra(root, m);
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(-25);
    root->left->right = new Node(1);
    root->left->left = new Node(20);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    cout << " The Max Path Sum is " << findMaxSum(root) << endl;

    // cout << "Height of the binary tree is  " << maxDepth(root) << endl;

    // vector<vector<int>> vec = level_order_traversal(root);
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     for (int j = 0; j < vec[i].size(); j++)
    //     {
    //         cout << vec[i][j] << endl;
    //     }
    // }
    // // This code works well
    return 0;
}