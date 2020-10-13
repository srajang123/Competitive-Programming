#include<bits/stdc++.h>
using namespace std;
struct bst
{
    struct bst* left;
    int data;
    struct bst* right;
};
struct bst* insert(int n,struct bst* root)
{
    if(root==NULL)
    {
        struct bst* tmp;
        tmp=(struct bst*)malloc(sizeof(struct bst*));
        tmp->data=n;
        tmp->left=NULL; 
        tmp->right=NULL;
        return tmp;
    }
    cout<<root->data<<":";
    if(n<root->data)
        root->left=insert(n,root->left);
    else
        root->right=insert(n,root->right);
    return root;
}
void preorder(struct bst *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct bst *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void postorder(struct bst *root)
{
    if(root!=NULL)
    {
        postorder(root->right);
        postorder(root->left);
        cout<<root->data<<" ";
    }
}
bool search(int n,struct bst *root)
{
    if(root==NULL)return false;
    if(root->data==n)
        return true;
    if(n<root->data)
        return search(n,root->left);
    else
        return search(n,root->right);
}
struct bst* minval(struct bst* root)
{
    struct bst* cur=root;
    while(cur && cur->left!=NULL)
        cur=cur->left;
    return cur;
}
struct bst* deleteNode(int n,struct bst* root)
{
    if(root==NULL)return root;
    if(n<root->data)
        root->left=deleteNode(n,root->left);
    else if(n>root->data)
        root->right=deleteNode(n,root->right);
    else
    {
        if(root->left==NULL)
        {
            root=root->right;
        }
        else if(root->right==NULL)
            root=root->right;
        else
        {
            struct bst* tmp=minval(root->right);
            root->data=tmp->data;
            root->right=deleteNode(tmp->data,root->right);
        }
        
    }
    return root;
}
int main()
{
    int c=1,n;
    struct bst *root=NULL;
    while(c!=0)
    {
        cout<<"\n1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Search\n6. Delete\n0. Exit";
        cout<<"\nEnter choice: ";
        cin>>c;
        switch(c)
        {
            case 1:
                cin>>n;
                root=insert(n,root);
                break;
            case 2:
                cout<<"\nPreorder Traversal: ";
                preorder(root);
                cout<<"\n";
                break;
            case 3:
                cout<<"\nPostorder Traversal: ";
                postorder(root);
                cout<<"\n";
                break;
            case 4:
                cout<<"\nInorder Traversal: ";
                inorder(root);
                cout<<"\n";
                break;
            case 5:
                cin>>n;
                if(search(n,root))
                    cout<<"Number found\n";
                else
                    cout<<"Number not found in BST\n";
            case 6:
                cin>>n;
                deleteNode(n,root);
        }
    }
}