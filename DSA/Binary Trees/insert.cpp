#include <iostream>
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

//queue implementation
Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
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



