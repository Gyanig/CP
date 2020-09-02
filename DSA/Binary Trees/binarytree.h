#ifndef BINARYNODE_H
#define BINARYNODE_H

#include<queue>
#include<cstddef>

//https://stackoverflow.com/questions/15891781/how-to-call-on-a-function-found-on-another-file

class  Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};


#endif
