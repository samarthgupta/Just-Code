#include<iostream>
#include <conio.h>
#include<string>

using namespace std;

template <class T>
class TreeNode
{

public:
	T data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

	TreeNode(T d)
	{
		data =d;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	TreeNode()
	{
		data =NULL;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

template <class T>
class Tree
{
public :
	TreeNode<T> root;
	bool createLinkToParent = false;

	Tree()
	{
		root = new TreeNode();
	}

	Tree(T d)
	{
		root = new TreeNode(d);
	}
	
	bool addNode(T d)
	{

	}

}