#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	
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

//using the queue technique coz its better
void deletedeep(Node* root, Node* deep_node)
{
	queue<Node*> q;
	q.push(root);

	Node* temp;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp == deep_node)
		{
			temp=NULL;
			delete (deep_node);
			return;
		}
		if(temp->right)
		{
			if(temp->right == deep_node)
			{	
				temp->right=NULL;
				delete (deep_node);
				return;
			}
			else
				q.push(temp->right);
		}
		if(temp->left)
		{
			if(temp->left == deep_node)
			{	
				temp->left=NULL;
				delete(deep_node);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}

Node* deletion(Node* root, int val)
{
	if(root==NULL)
		return NULL;

	if(root->left == NULL && root->right == NULL)
	{
		if(root->data == val)
			return NULL;
		else
			return root;
	}

	queue<Node*> q;
	q.push(root);

	Node* temp;
	Node* delete_node= NULL;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp->data == val)
			delete_node=temp;
		
		if(temp->left)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);
	}
	if(delete_node!=NULL)
	{
		int a=temp->data;
		deletedeep(root,temp);
		delete_node->data= a;
	}
	return root;
}

// //queue implementation
// Node* InsertNode(Node* root, int data)
// {
//     // If the tree is empty, assign new node address to root
//     if (root == NULL) {
//         root = CreateNode(data);
//         return root;
//     }
 
//     // Else, do level order traversal until we find an empty
//     // place, i.e. either left child or right child of some
//     // node is pointing to NULL.
//     queue<Node*> q;
//     q.push(root);
 
//     while (!q.empty()) {
//         Node* temp = q.front();
//         q.pop();
 
//         if (temp->left != NULL)
//             q.push(temp->left);
//         else {
//             temp->left = CreateNode(data);
//             return root;
//         }
 
//         if (temp->right != NULL)
//             q.push(temp->right);
//         else {
//             temp->right = CreateNode(data);
//             return root;
//         }
//     }
// }


int main()
{
	Node* root = new Node(10);
    root->left =  new Node(11);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right =  new Node(8);

	inorder(root);

	int input = 12;
	// cin>>input;
	cout<<endl;
	insert(root,input);

	inorder(root);

	cout<<"\ndeletion"<<endl;
	int value=11;
	root = deletion(root,value);
    inorder(root);
	return 0;
}



