#include <iostream>
#include <cmath>
using namespace std;

typedef struct tnode
{
      int field;
      struct tnode * left, * right;
} tnode;

tnode *addnode(int x, tnode *tree);
int CheckTreeHeight(tnode *root);
bool IsBalanced(tnode *root);



int main()
{
    tnode *pTree = NULL;
    int mas[15]={14, 8, 1, 13, 7, 12, 6, 2, 9, 0, 11, 10, 4, 3, 5}, i;

    for (i = 0; i < 15; i++)
        addnode(mas[i], pTree);
	cout << IsBalanced(pTree);

    return 0;
}

tnode *addnode(int x, tnode *tree){
    if(tree == NULL){
        tree = new tnode;
        tree->field = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if(x < tree->field)
        tree->left = addnode(x, tree->left);
        else
        tree->right = addnode(x, tree->right);
        return(tree);
}

int CheckTreeHeight(tnode *root)
{
if(root == NULL) return 0;


int leftChildHeight = CheckTreeHeight(root->left);
if(leftChildHeight == -1) return -1;


int rightChildHeight = CheckTreeHeight(root->right);
if(rightChildHeight == -1) return -1;


int heightDifference = leftChildHeight - rightChildHeight;

if(fabs(heightDifference) > 1)
return -1;
else
return fmax(leftChildHeight, rightChildHeight) + 1;
}

bool IsBalanced(tnode *root)
{
if(CheckTreeHeight(root) == -1)
{
return false;
}
else
{
return true;
}
}
