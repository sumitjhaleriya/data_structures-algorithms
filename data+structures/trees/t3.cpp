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
int findmax(struct Node *root)
{
    int root_val, left, right, max = INT_MIN;
    if (root != NULL)
    {
        root_val = root->data;
        left = findmax(root->left);
        right = findmax(root->right);
        if (left > right)
        {
            max = left;
        }
        else
        {
            max = right;
        }
        if (root_val > max)
        {
            max = root_val;
        }
    }
    //cout <<"max:" << max <<" left: "<<left<<" right: " <<right<<endl;
    return max;
}
void preinpost(struct Node *root)
{

    stack<pair<struct Node *, int>> st;
    st.push({root, 1});
    vector<int> pre, post, in;
    if (root == NULL)
        return;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    cout << "pre : " << endl;
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i];
    }
    cout << "\n in : " << endl;
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i];
    }
    cout << "\n post : " << endl;
    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i];
    }
}
void level_order(struct Node *root)
{
    struct Node *temp;
    queue<struct Node *> q;
    if (!root)
        return;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        cout << temp->data << endl;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
void testing_fnc(struct Node *root){
    struct Node *t = root,*u=root;
    while (t->left != NULL)
    {
        t = t->left;
    }
    while (u->right != NULL)
    {
        u = u->right;
    }
    cout<<"most left_node : "<<t->data<<endl;
    cout<<"most right_node : "<<u->data<<endl;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // vector<vector<int>> vec = level_order_traversal(root);
    // for (int i = 0; i < vec.size() ; i++)
    // {
    //     for (int j = 0; j < vec[i].size(); j++)
    //     {
    //         cout << vec[i][j] << endl;
    //     }
    // }
    // This code works well
    // level_order(root);
    // preinpost(root);
    testing_fnc(root);
    return 0;
}