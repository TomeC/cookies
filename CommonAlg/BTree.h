#ifndef __TREE_H__
#define __TREE_H__
#include <iostream>
using namespace std;

template <typename T> class BTree;
template <typename T>
class TreeNode
{
	friend class BTree<T>;
private:
	TreeNode ();
	TreeNode (const T &value):lchild (0), rchild (0)
	{
		data = value;
	}
private:
	T data;
	TreeNode<T> *lchild;
	TreeNode<T> *rchild;
};

template <typename T>
class BTree
{
public:
	BTree ();
	void InsertNode (const T &);
	void PreOderTraverse ();
	void InOrderTraverse ();
	void PostOrderTraverse ();
private:
	TreeNode<T> *RootPtr;
	void InsertNoder (TreeNode <T> **, const T &);
	void PreOderTraverser (TreeNode <T> *) const; 
	void InOrderTraverser (TreeNode <T> *) const;
	void PostOrderTraverser (TreeNode <T> *) const;
	void visit (TreeNode <T> *) const;
};

template <typename T>
BTree<T>::BTree ()
{
	RootPtr = NULL;
}

template <typename T>
void BTree<T>::InsertNode (const T &value)
{
	InsertNoder (&RootPtr, value);
}

template <typename T>
void BTree<T>::InsertNoder (TreeNode <T> **ptr, const T &value)
{
	if (*ptr == NULL)
	{
		*ptr = new TreeNode<T>(value);
	}
	else
	{
		if ((*ptr)->data < value)
		{
			InsertNoder (&((*ptr)->rchild), value);
		}
		else
		{
			InsertNoder (&((*ptr)->lchild), value);
		}
	}
}

template <typename T>
void BTree <T>::InOrderTraverse ()
{
	InOrderTraverser (RootPtr);
}

template <typename T>
void BTree <T>::InOrderTraverser (TreeNode <T> *ptr) const
{
	if (ptr != NULL)
	{
		visit (ptr);
		InOrderTraverser (ptr->lchild);
		InOrderTraverser (ptr->rchild);
	}
}

template <typename T>
void BTree<T>::PreOderTraverse ()
{
	PreOderTraverser (RootPtr);
}

template <typename T>
void BTree <T>::PreOderTraverser (TreeNode <T> *ptr) const
{
	if (ptr != NULL)
	{
		PreOderTraverser (ptr->lchild);
		visit (ptr);
		PreOderTraverser (ptr->rchild);
	}
}

template <typename T>
void BTree <T>::PostOrderTraverse ()
{
	PostOrderTraverser (RootPtr);
}

template <typename T>
void BTree <T>::PostOrderTraverser (TreeNode <T> *ptr) const
{
	if (ptr != NULL)
	{
		PostOrderTraverser (ptr->lchild);
		PostOrderTraverser (ptr->rchild);
		visit (ptr);
	}
}

template <typename T>
void BTree <T>::visit (TreeNode <T> *ptr) const
{
	cout<<ptr->data<<" ";
}

#endif
/*
//test program, another file
#include <iostream>
#include <string>
#include "BTree.h"
using namespace std;

int main ()
{
	BTree<int> intTree;
	int intValue;
	cout<<"Input 5 integer values\n";
	for( int i = 0; i < 5; i++ )
	{
		cout << "The " << i+1 << " number is: ";
		cin >> intValue;
		intTree.InsertNode(intValue);
	}


	cout << "\npreOrderTranversal:\n" ;
	intTree.PreOderTraverse();


	cout << "\ninOrderTranversal:\n" ;
	intTree.InOrderTraverse();

	cout << "\npostOrderTranversal:\n" ;
	intTree.PostOrderTraverse();
	
	return 0;
}

*/
