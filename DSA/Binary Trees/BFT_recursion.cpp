//traversals 
// poor as it take O(n^2) time complexity and O(n) space complexity
//BFS or Level order traversals
#include<bits/stdc++.h>
using namespace std;

int lh,rh;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* newNode(int d){
	Node* new_node= new Node();
	new_node->data=d;
	new_node->left=NULL;
	new_node->right=NULL;
}

int height(Node* n);
void printlevel(Node* root,int level);

void bft(Node* root)
{
	int h= height(root);
	
	for(int i=1;i<=h;i++)
	{
		printlevel(root,i);
	}
	
}

void printlevel(Node* root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
		cout<<root->data<<" ";	
	else if(level>1)
	{
		printlevel(root->left,level-1);
		printlevel(root->right,level-1);
	}
	
}


int height(Node* n)
{
	if(n==NULL)
		return 0;
	else
	{
//		cout<<lh<<" "<<rh<<endl;
		cout<<n->data<<" ";
		int lh=height(n->left);
		int rh=height(n->right);
		cout<<lh<<" "<<rh<<endl;
		
		
		if(lh>rh)
		{
			return (lh+1);
		}
		else
		{	
			return (rh+1);	
		}
	}	
}

int main()
{
	Node* root= newNode(10);
	root->left=newNode(20);
	root->right=newNode(30);
	root->left->left=newNode(40);
	root->left->right=newNode(50);
	root->left->right->left=newNode(60);
	root->left->right->right=newNode(70);
	
	bft(root);
		
	return 0;
}
