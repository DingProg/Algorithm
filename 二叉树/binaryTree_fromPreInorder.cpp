
#include <iostream>

using namespace std;

typedef struct STreeNode{
    int value;
    STreeNode * left;
    STreeNode * right;
}TreeNode;


/**
 *         10
 *     6          14
 *  4   8      12   16
 
 pre:10 6 4 8 14 12 16
 inOrder:4 6 8 10 12 14 16
 post:4 8 6 12 16 14 10
 */

TreeNode * initTreeFromOrder(int * pre,int *inOrder, int length){
    if(length <= 0){
        return NULL;
    }
    TreeNode *root = new TreeNode();
    root->value = *pre;
    root->left = NULL;
    root->right = NULL;
    
    int index = 0;
    
    for(;index < length;index++){
        if(*pre == inOrder[index]){
            break;
        }
    }
    
    root->left = initTreeFromOrder(pre + 1, inOrder, index);
    root->right = initTreeFromOrder(pre + index + 1, inOrder +index + 1, length - (index + 1));
    
    return root;
}

/**
 *
 *后序遍历
 **/
void traversalPost(TreeNode * root){
    if(root != NULL){
        traversalPost(root->left);
        traversalPost(root->right);
        cout<<root->value<<" ";
    }
}

int main()
{
    int pre[] ={10,6,4,8,14,12,16};
    int in[] ={4,6,8,10,12,14,16};
    TreeNode *root = initTreeFromOrder(pre,in,7);
    traversalPost(root);
    return 0;
}
