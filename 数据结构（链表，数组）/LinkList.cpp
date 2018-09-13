#include <iostream>

using namespace std;

typedef struct Node{
    int value;
    Node * next;
}LNode;

/**
    通过数组构建链表
 **/
LNode * buildLinkList(int * array,int len){
    LNode * head = new LNode();
    LNode * p = new LNode();
    head = p;
    for(int i= 0;i<len;i++){
        LNode * tnode = new LNode();
        tnode->value = array[i];
        tnode->next = NULL;
    
        p->next = tnode;
        p=tnode;
    }
    return head;
}


/**
    反转
 **/
LNode * reverse(LNode * head){
    if (head == NULL || head->next == NULL) return head;
    LNode *p = head->next,*q=head->next->next,*lNext;
    head->next->next = NULL;
    while (q)
    {
        lNext = q->next;
        q->next = p;
        p = q;
        q = lNext;
    }
    head->next = p;
    return head;
    
}

/**
    指定位置插入
 **/
bool insert(LNode * head,int indexKey,int value){
    if (head == NULL) return false;
    
    LNode * node = new LNode();
    node->next = NULL;
    node->value = value;
    
    LNode *p = head;
    int count = 0;
    while (p != NULL) {
        if(count == indexKey){
            LNode *q = p->next;
            p->next = node;
            node->next = q;
            return true;
        }
        count++;
        p=p->next;
    }
    return false;
}

/**
    删除
 **/
bool deleteNode(LNode * head,int value){
    if (head == NULL) return false;
    LNode *p = head->next,*q = head;
    while(p != NULL){
        if(p->value == value){
            q->next = p->next;
            return true;
        }
        q = q->next;
        p = p->next;
    }
    return false;
}

void printNodeVaule(LNode * head){
    if (head == NULL) return;
    LNode *p = head->next;
    while (p != NULL) {
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8};
    LNode * head =buildLinkList(a,8);
    printNodeVaule(head);
    LNode * head1 =reverse(head);
    printNodeVaule(head1);
    cout<<"insert = " <<insert(head1, 5, -100)<<endl;
    printNodeVaule(head1);
    cout<<"delete = " <<deleteNode(head1, -100)<<endl;
    printNodeVaule(head1);
    return 0;
}
