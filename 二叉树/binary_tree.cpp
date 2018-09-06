
#include <iostream>
#include <queue>
#include <stack>

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
    temp3->value = 12;
    
    TreeNode *temp4 = new TreeNode();
    temp4->left = NULL;
    temp4->right = NULL;
    temp4->value = 16;
    
    TreeNode *temp5 = new TreeNode();
    temp5->left = temp1;
    temp5->right = temp2;
    temp5->value = 6;
    
    TreeNode *temp6 = new TreeNode();
    temp6->left = temp3;
    temp6->right = temp4;
    temp6->value = 14;
    
    root->left = temp5;
    root->right = temp6;
    root->value = 10;
    return root;
}

/**
 *
 *先序遍历
 **/
void traversalPre(TreeNode * root){
    if(root != NULL){
        cout<<root->value<<endl;
        traversalPre(root->left);
        traversalPre(root->right);
    }
}

/**
 *  广度优先遍历
 **/
void layerTranversal(TreeNode * root){
    if(root == NULL) return;
    queue <TreeNode *> q;
    q.push(root);
    
    while(!q.empty()){

        TreeNode* node = q.front();
        q.pop();
        
        cout<<node->value<<endl;
        
        if(node->left != NULL){
            q.push(node->left);
        }
        if(node->right != NULL){
            q.push(node->right);
        }
    }
}

/**
 * 非递归 先序列遍历
 **/
void traveralNPre(TreeNode * root){
    if(root == NULL) return;
    stack<TreeNode *> s_stack;
    s_stack.push(root);
    
    while(!s_stack.empty()){
        TreeNode* node = s_stack.top();
        s_stack.pop();

        cout<<node->value<<endl;
        
        if(node->right != NULL){
            s_stack.push(node->right);
        }
        
        if(node->left != NULL){
            s_stack.push(node->left);
        }
      
    }
}


int main()
{
    TreeNode *root = initTree();
    //traversalPre(root);
    //layerTranversal(root);
    traveralNPre(root);
    return 0;
}
