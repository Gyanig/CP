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
    stack<Node*> s;
    Node* curr= temp;

    while(curr!=NULL || s.empty()==false)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" "<<endl;
        curr=curr->right;
    }
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

	return 0;
}





