#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* parent;
	Node* child;
	Node* left;
	Node* right;
	Node(int val)
	{
		data=val;
		parent=NULL;
		child=NULL;
		left=NULL;
		right=NULL;
	}
};

Node* mini = NULL;
int no_of_nodes=0;

void insert(int val)
{
	Node* newNode=new Node(val);
	newNode->parent = NULL;
    newNode->child = NULL;
	newNode->left=newNode;
	newNode->right=newNode;
	if(mini!=NULL)
	{
		(mini->left)->right= newNode;
		newNode->right= mini;
		newNode->left=mini->left;
		mini->left=newNode;
		if(newNode->data <mini->data)	
			mini=newNode;
	}
	else
		mini=newNode;
}

void display(Node* mini)
{
	Node* ptr=mini;
	if(ptr==NULL)
		cout<<"Heap is empty"<<endl;

	else {
		cout<<"root nodes are :"<<endl;
		do{
			cout<<ptr->data;
			ptr=ptr->right;
			if(ptr!=mini){
				cout<<"-->";
			}
		}while(ptr!=mini && ptr->right!=NULL);
		cout<< "\nThe heap has " << no_of_nodes << " nodes" << endl;
	}
}
void find_min(Node* mini)
{
    cout << "min of heap is: " << mini->data << endl;
}


int main()
{

 
    no_of_nodes = 7;
    insert(4);
    insert(3);
    insert(7);
    insert(5);
    insert(2);
    insert(1);
    insert(10);
 
    display(mini);
 
    find_min(mini);
 

	return 0;
}