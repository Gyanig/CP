//diameter of bt
#include<bits/stdc++.h>
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

//insert first position available

void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
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

int max(int a,int b) {return (a>b)?a:b;}

int  height(Node* temp)
{
	if(!temp) return 0;
	return 1+max(height(temp->left),height(temp->right));
}


int diameter(Node* temp)
{	
	if(temp == NULL) return NULL;
	int lheight= height(temp->left);
	int rheight= height(temp->right);

	int ldiameter= diameter(temp->left);
	int rdiameter= diameter(temp->right);

	return max(lheight+rheight+1, max(ldiameter,rdiameter));
}


int main()
{
	Node* root = new Node(10);
    root->left =  new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right =  new Node(8);

	inorder(root);

	int input = 12;
	// cin>>input;
	cout<<endl;
	insert(root,input);

	inorder(root);
	cout<<""<<endl;

	cout<<"Diameter :"<<diameter(root)<<endl;;

	return 0;
}





