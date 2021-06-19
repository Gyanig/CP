#include <bits/stdc++.h>
using namespace std;

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

        int minValue(BST* root)
        {
            BST* n = root;
            while(n && n->left!=NULL)
                n=n->left;
            
            return n->data;
        }
};

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
    int m=b.minValue(root);
    cout<<"\n"<<m<<" minimum value of the BST\n";
    return 0;
}