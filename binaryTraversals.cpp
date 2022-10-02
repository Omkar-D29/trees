#include<bits/stdc++.h>
#include <iostream>
#include<stack>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *root)
{
    cout << "Enter the data for node : ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter Left node of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter Right Node of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //juna level complete zala
            cout << endl;
            if(!q.empty()) { 
                //queue madhe child nodes ahet
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void postorderIterative(node* root)
{
    if (root == NULL && root) {
        return;
    }
 
    stack<node*> st;
    st.push(root);
 
    while (!st.empty())
    {
        node* curr = st.top();
        st.pop();
 
        cout<<curr->data<<" ";
 
        if (curr->left) {
            st.push(curr->left);
        }
 
        if (curr->right) {
            st.push(curr->right);
        }
    }
}
void inOrder(node* root){

    if (root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void preOrder(node* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node* root){
    if (root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(int argc, char const *argv[])
{
    node *root = NULL;
    root = buildtree(root);
//     Fixed inOrder Traversal
    inOrder(root);
    
    postorderIterative(root);
    // postOrder(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

// 1 5 17 3 11 7 
