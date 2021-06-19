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
        void inorderpredsucc(BST* temp,BST*& pred, BST*& succ, int val)
        {
            if(temp==NULL)  return;
            
            if(temp->data == val)
            {
                if(temp->left!=NULL)
                {
                    BST* n=temp->left;
                    while(n->right)
                        n=n->right;
                    pred=n;
                }

                if(temp->right!=NULL)
                {
                    BST* n=temp->right;
                    while(n->left)
                        n=n->left;
                    succ=n;
                }
                return;
            }

            if(temp->data>val)
            {
                succ=temp;
                inorderpredsucc(temp->left,pred,succ,val);
            }
            else
            {
                pred=temp;
                inorderpredsucc(temp->right,pred,succ,val);
            }
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
    int key = 50;

    BST* pred=NULL, *succ=NULL;
    b.inorderpredsucc(root, pred, succ, key);
    if (pred != NULL)
      cout << "Predecessor is " << pred->data << endl;
    else
      cout << "No Predecessor";
 
    if (succ != NULL)
      cout << "Successor is " << succ->data;
    else
      cout << "No Successor";

    return 0;
}