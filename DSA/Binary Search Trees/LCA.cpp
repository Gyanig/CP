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


        BST* LCA(BST* temp, int x, int y)
        {
            if(temp==NULL)return NULL;

            if(temp->data > x && temp->data>y )
                return LCA(temp->left,x,y);
            if(temp->data < x && temp->data<y )   
                return LCA(temp->right,x,y);

            return temp;    
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
    cout<<endl;
    
    int x =20,y=40;
    BST* res=b.LCA(root,x,y);
    cout<<"LCA "<<res->data<<endl;
    return 0;
}