/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <iostream>
#include <queue>
using namespace std;

#define NULL 0
class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int maxDepth(TreeNode *root) {
		int depth = 0;
		TreeNode *tmp, *flag = NULL;
		que.push (root);
		que.push (flag);

		while (!que.empty ())
		{
			tmp = que.front ();
			if (tmp == NULL)
			{
				depth++;
				que.pop ();
				if (!que.empty ())
					que.push (flag);
				continue;
			}  
			if (tmp->left != NULL)    
				que.push (tmp->left);
			if (tmp->right)
				que.push (tmp->right);
			que.pop ();
		}
		return depth;
	}
	bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
			return true;
		
		if (p != NULL && q != NULL)
		{
			if (p->val == q->val)
			{
				if (isSameTree (p->left, q->left) && 
					isSameTree (p->right, q->right)
				)
				{
					return true;
				}
			}
		}
		return false;
    }
private:
	queue <TreeNode *> que;
};

int main ()
{
	TreeNode *root1 = new TreeNode (1);
	root1->left = new TreeNode (2);
	root1->right = new TreeNode (3);
	//root1->left->left = new TreeNode (4);

	TreeNode *root2 = new TreeNode (1);
	root2->left = new TreeNode (2);
	root2->right = new TreeNode (3);
	root2->left->left = new TreeNode (4);
	Solution s;
	cout<<s.isSameTree(root1, root2)<<endl;
}