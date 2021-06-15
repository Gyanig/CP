#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    bool lthread;
    bool rthread;

    Node(int val)
    {
        left=right=NULL;
        data=val;
        lthread=rthread=false;
    }
};

Node* insert(Node* root, int input)
{
    Node* ptr,*par;
    ptr=root;
    par=NULL;

    while(ptr!=NULL)
    {
        if(input==(ptr->data))
        {
            cout<<"Exists"<<endl;
            return root;
        }

        par=ptr;

        if(input<ptr->data)
        {
            if(ptr->lthread==false)
                ptr=ptr->left;
            else
                break;
        }
        else
        {
            if(ptr->rthread ==false)
                ptr=ptr->right;
            else
                break;
        }
    }

    Node* temp= new Node(input);
    temp->lthread=true;
    temp->rthread=true;

    if (par == NULL)
    {
        root = temp;
        temp -> left = NULL;
        temp -> right = NULL;
    }
    else if (input < (par->data))
    {
        temp -> left = par -> left;
        temp -> right = par;
        par -> lthread = false;
        par -> left = temp;
    }
    else
    {
        temp -> left = par;
        temp -> right = par -> right;
        par -> rthread = false;
        par -> right = temp;
    }
 
    return root;

}


Node* inorderSuccessor(Node* temp)
{
    if(temp->rthread==true)
        return temp->right;
    
    temp=temp->right;
    while(temp->lthread==false)
        temp=temp->left;

    return temp;
}

void inorder(Node* root)
{
    if(root==NULL) return;

    Node* temp=root;

    while(temp->lthread==false)
        temp=temp->left;

    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = inorderSuccessor(temp);
    }    
}

int main()
{

    Node* root=NULL;

    root= insert(root,20);
    root= insert(root,10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);
 
    inorder(root);
    return 0;

}