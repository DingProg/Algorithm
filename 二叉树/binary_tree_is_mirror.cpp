
#include <iostream>

using namespace std;

typedef struct STreeNode{
    int value;
    STreeNode * left;
    STreeNode * right;
}TreeNode;


/**
 *         10
 *     6          6
 *  4   8      8    4
 */
TreeNode * initTree(){
    
    TreeNode *root = new TreeNode();
    
    TreeNode *temp1 = new TreeNode();
    temp1->left = NULL;
    temp1->right = NULL;
    temp1->value = 4;
    
    TreeNode *temp2 = new TreeNode();
    temp2->left = NULL;
    temp2->right = NULL;
    temp2->value = 8;
    
    TreeNode *temp3 = new TreeNode();
    temp3->left = NULL;
    temp3->right = NULL;
    temp3->value = 8;
    
    TreeNode *temp4 = new TreeNode();
    temp4->left = NULL;
    temp4->right = NULL;
    temp4->value = 4;
    
    TreeNode *temp5 = new TreeNode();
    temp5->left = temp1;
    temp5->right = temp2;
    temp5->value = 6;
    
    TreeNode *temp6 = new TreeNode();
    temp6->left = temp3;
    temp6->right = temp4;
    temp6->value = 6;
    
    root->left = temp5;
    root->right = temp6;
    root->value = 10;
    return root;
}

/**
 *  判断一棵二叉树是否中轴对称的
 **/
bool isTreeMirror(TreeNode *left,TreeNode * right){
    //如果两个都为空，说明是对称的
    if(left == NULL && right == NULL){
        return true;
    }
    //上面条件满足，有一个为空，则不对称
    if(left == NULL || right == NULL){
        return false;
    }
    
    //值如果不等，也不对称
    if(left->value != right->value){
        return false;
    }
    
    //值相等，进行下一次判断
    bool out = isTreeMirror(left->left, right->right);
    bool inner = isTreeMirror(left->right, right->left);
    return out && inner;
}

int main()
{
    TreeNode * root =initTree();
    cout<<"isTreeMirror="<<isTreeMirror(root->left, root->right)<<endl;
    return 0;
}
