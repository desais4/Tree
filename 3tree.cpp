#include<iostream>
using namespace std;
#include "tree_stack.h"
#include<string.h>
	
int max(int value1,int value2)
{
	return((value1>value2) ? value1 : value2);
}

class tree
{
	struct node *nn=NULL;
	char x;
	int c;
	static int cnt;
	public:
	
	struct node * insert(struct node *root)
	{
		if(root==NULL)
		{
			nn=new node;
			cout<<"\n Enter root value : ";
			cin>>nn->data;
			root=nn;
		}
		else
		{
			cout<<"\n Enter a child node at \n1.Left 2.Right \n of Node  "<<root->data<<"\n";
			cin>>c;
			switch(c)
			{
				case 1:
				if(root->left==NULL)
				{
					nn=new node;
					cout<<"\n Enter value : ";
					cin>>nn->data;
					root->left=nn;
				}
				else
				{
					insert(root->left);
				
				}
				break;
				
				case 2:
				if(root->right==NULL)
				{
					nn=new node;
					cout<<"\n Enter value : ";
					cin>>nn->data;
					root->right=nn;
				}
				else
				{
					insert(root->right);
				
				}
				break;
			}
		
		
		}
	
	
	return root;
	}
	void leaf_node(struct node *root);
	struct node *copy(struct node *root);
	int depth(struct node *root);
};

void tree :: leaf_node(struct node *root)
{
	struct node*nodeptr;
	 nodeptr=root;
		if(nodeptr->left==NULL && nodeptr->right==NULL)
		{
				cout<<" "<<nodeptr->data;
		}
		if(nodeptr->left!=NULL)
		    	leaf_node(nodeptr->left);
		if(nodeptr->right!=NULL)  
				leaf_node(nodeptr->right);
}

int tree :: depth(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right==NULL)
		return 0;
				
		return(max(depth(root->left), depth(root->right))+1);
}

struct node *tree :: copy(struct node *root)
{
	struct node *temp=NULL;	
	char a[20];
	int i=0;
	if(root==NULL)
		return NULL;
	temp=new node;
	temp=root;
		cout<<temp->data;
		temp->left=copy(root->left);
		temp->right=copy(root->right);
		return temp;	
}

int main()
{
	tree T;
	struct node *root=NULL,*root1=NULL;
	int ch,choice,r,z;
	
	do
	{
		cout<<"\n1.Insert a node \n2.Display \n3.Display depth \n4.Display leaf nodes \n5.Create copy of tree \n6.exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			do
			{
				cout<<"\n Do you want to insert a node ";
				cout<<"\n1.YES 2.NO : ";
				cin>>ch;
				if(ch==1)
					root=T.insert(root);
			}while(ch!=2);
			break;
			
			case 2:
			cout<<"\n1.Recursive \n2.Non-recursive : ";
			cin>>r;
			if(r==1)
			{
				cout<<"\n1.Preorder \n2.Inorder \n3.Postorder  : ";
				cin>>z;
				switch(z)
				{
					case 1:
					cout<<"\nPreorder traversal is : ";
					preorder(root);
					break;
					
					case 2:
					cout<<"\nInorder traversal is : ";
					inorder(root);
					break;
					
					case 3:
					cout<<"\nPostorder traversal is : ";
					postorder(root);
					break;
					
				}
			}
			if(r==2)
			{
				cout<<"\n1.Preorder \n2.Inorder \n3.Postorder  : ";
				int z1;
				cin>>z1;
				switch(z1)
				{
					case 1:
					cout<<"\nPreorder traversal is : ";
					nrec_preorder(root);
					break;
					
					case 2:
					cout<<"\nInorder traversal is : ";
					nrec_inorder(root);
					break;
					
					case 3:
					cout<<"\nPostorder traversal is : ";
					nrec_postorder(root);
					break;
				}
			}
			break;
			
			case 3:
			int cnt;
			cnt=T.depth(root);
			cout<<"\n Depth of tree is : "<<cnt;
			break;
			
			case 4:
			cout<<"\n Leaf nodes are : ";
			T.leaf_node(root);
			break;
			
			case 5:
			cout<<"\n Preorder travresal of original tree is :";
			nrec_preorder(root);
			cout<<"\n Copied tree is : ";
			root1=T.copy(root);
			break;	
		}
	}while(choice!=6);

	return 0;
}


