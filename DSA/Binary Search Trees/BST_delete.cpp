#include<bits/stdc++.h>
using namespace std;
//deletion operation
//	- delete leaf
//	- delete node with child
//	- delete node without child

class BST{
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
		
		BST* minValue(BST*); //inorder successor
		
		BST* delete_child(BST*,int);
		
};

//deleting child has three cases: delete leaf, delete child with one leaf, delete child with two leafs
BST* BST::minValue(BST* n)
{
	BST* c=n;
	while(c && c->left!=NULL)
	{
		c=c->left;
	}
	return c;
}


BST* BST::delete_child(BST* root,int k)
{
	//base condition
	if(root==NULL)
		return root;
	
	//traverse to left or right
	if(k<root->data)
		root->left=delete_child(root->left,k);
		
	else if(k>root->data)
		root->right=delete_child(root->right,k);
		
	else	
	{
		//if it has no child or one child
		if(!root->left)
		{
			BST* n=root->right;
			free(root);
			return n;
		}
		else if(!root->right)
		{
			BST* n=root->left;
			free(root);
			return n;
		}
		
		//if above conditions are untrue then it has two child
		
		BST* n=minValue(root->right);
		root->data=n->data;
		root->right=delete_child(root->right,n->data);
		
		
		//optimatization from O(n)
		Node* succParent = root; 
          
        // Find successor 
//	        Node *succ = root->right; 
//	        while (succ->left != NULL) { 
//	            succParent = succ; 
//	            succ = succ->left; 
//	        } 
//	  
//	        // Delete successor.  Since successor 
//	        // is always left child of its parent 
//	        // we can safely make successor's right 
//	        // right child as left of its parent. 
//	        // If there is no succ, then assign  
//	        // succ->right to succParent->right 
//	        if (succParent != root) 
//	            succParent->left = succ->right; 
//	        else
//	            succParent->right = succ->right; 
//	  
//	        // Copy Successor Data to root 
//	        root->key = succ->key; 
//	  
//	        // Delete Successor and return root 
//	        delete succ;          
//	        return root; 
		
	}
	
	return root;
	
}

int main()
{
	BST b, *root = NULL; 
	
    root = b.insert(root, 50); 
	b.insert(root, 30); 
    b.insert(root, 20); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    b.insert(root, 80); 
//	b.insert(root, 20);

	cout << "Inorder traversal of the given tree \n"; 
    b.inorder(root); 
  
    cout<<"\nDelete 20\n"; 
    root = b.delete_child(root, 20); 
    cout<<"Inorder traversal of the modified tree \n"; 
    b.inorder(root); 
  
    cout<<"\nDelete 30\n"; 
    root = b.delete_child(root, 30); 
    cout<<"Inorder traversal of the modified tree \n"; 
    b.inorder(root); 
  
    cout<<"\nDelete 50\n"; 
    root = b.delete_child(root, 50); 
    cout<<"Inorder traversal of the modified tree \n"; 
    b.inorder(root);   	
	
	return 0;
}
