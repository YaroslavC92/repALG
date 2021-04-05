#include <iostream>
#include <cmath>
using namespace std;

typedef struct tnode
{
      int field;
      struct tnode * left, * right;
} tnode;

tnode *addnode(int i, int x, tnode *tree);
//int CheckTreeHeight(tnode *root);
//bool IsBalanced(tnode *root);



int main()
{
    //tnode *pTree = NULL;
    tnode treemas[50];

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 10000; j++){
            int temp = rand() % 500000;
            addnode(i, temp, treemas);
        }
    }
    return 0;
}

tnode *addnode(int i, int x, tnode *tree){
    if(tree == NULL){
        tree = new tnode;
        tree[i].field = x;
        tree[i].left = NULL;
        tree[i].right = NULL;
    }
    else if(x < tree[i].field)
        tree[i].left = addnode(i, x, tree[i].left);
        else
        tree[i].right = addnode(i, x, tree[i].right);
        return(tree);
}
