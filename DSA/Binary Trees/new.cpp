#include<bits/stdc++.h>
using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
	
	Node(char val)
	{
		data=val;
		left= NULL;
		right= NULL	;
	}
};

int search(char arr[],int start,int end,char value)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(arr[i]==value) 
			return i;
	}
}
//tree from traversal
Node* buildTree(char in[],char pre[],int inStart,int inEnd)
{
	static int preIndex = 0;

	if(inStart > inEnd)
		return NULL;
	
	Node* newNode = new Node(pre[preIndex++]);

	if(inStart == inEnd)
		return newNode;

	
	int newIndex = search(in, inStart, inEnd, newNode->data);
	newNode->left=buildTree(in,pre,inStart,newIndex-1);
	newNode->right=buildTree(in,pre,newIndex+1,inEnd);

	return newNode;
}


void printInorder(Node* temp)
{
	if(temp==NULL) return;
	printInorder(temp->left);
	cout<<temp->data<<" ";
	printInorder(temp->right);
}

int main()
{
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(in, pre, 0, len - 1);

    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}