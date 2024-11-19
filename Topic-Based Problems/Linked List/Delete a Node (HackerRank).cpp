// Problem Link : https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(llist->next==NULL) return llist=NULL;
    if(position==0){
        llist=llist->next;
        return llist;
    }
    SinglyLinkedListNode* node=llist;
    int index=-1;
    while(node!=NULL){
        index++;
        if(index==position-1) break;
        node=node->next;
    }
    node->next=node->next->next;
    return llist;
}
