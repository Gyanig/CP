#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
	{
		data=val;
		left= NULL;
		right= NULL	;
	}

};

int arr[100];
int n=0;
//counting is done in inorder traversal function
//using a global variable
void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    // cout << temp->data << ' ';
    arr[n]=temp->data;
    n++;
    inorder(temp->right);
}


void insert(Node* temp, int val)
{	
	if(temp == NULL )
		return;

	insert(temp->left,val);
	// cout<<temp->data<<endl;

	if((temp->right==NULL && temp->left!=NULL) || (temp->right!=NULL && temp->left==NULL))
	{
		Node* newNode= new Node(val);
		if(temp->right==NULL)
		{
			temp->right=newNode;
		}
		else
		{
			temp->left=newNode;
		}
		// cout<<val<<endl;			
	}

	insert(temp->right,val);
}

class BST
{
    public:
        int data;
		BST* left;
		BST* right;
		
		BST()
		{
			data=0;
			left=NULL;
			right=NULL;
		}
		
		BST(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
		
		BST* insert(BST* root,int d)
		{
			if(!root)
			{
				return new BST(d);
			}
			
			if(d>root->data)
			{
				root->right= insert(root->right,d);
			}
			else
			{
				root->left= insert(root->left,d);
			}
			return root;
		}

		void inorder(BST* root)
		{
			if(!root)
			{
				return;
			}
				
			inorder(root->left);
			cout<<root->data<<" ";
			inorder(root->right);
		}
};



int main()
{
    Node* root1 = new Node(10);
    root1->left =  new Node(11);
    root1->left->left = new Node(7);
    root1->right = new Node(9);
    root1->right->left = new Node(15);
    root1->right->right =  new Node(8);

	inorder(root1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

	BST b, *root2 = NULL; 
    root2 = b.insert(root2, arr[0]);
    for(int i=1;i<n;i++)
	    b.insert(root2, arr[i]); 
    
	cout << "Inorder traversal of the given tree \n"; 
    b.inorder(root2); 
    cout<<endl;
    


    return 0;
}