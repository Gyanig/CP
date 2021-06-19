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

        int ceil(BST* temp, int input)
        {
            if(temp==NULL) return -1;

            if(temp->data==input) return temp->data;

            if(temp->data<input) return ceil(temp->right, input);

            int c= ceil(temp->left,input);
            return (c>=input)?c:temp->data;
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
    
    for(int i=10;i<100;i+=10)
        cout<<i<<" "<<b.ceil(root,i)<<endl;

    return 0;
}