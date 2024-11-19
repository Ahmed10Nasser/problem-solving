// Problem Link : https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem


SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* node=llist;
    int index=-1;
    while(node!=NULL){
        index++;
        if(index==position-1) break;
        node=node->next;
    }
    SinglyLinkedListNode* newNode=new SinglyLinkedListNode(data);
    if(position==0) newNode->next=llist, llist=newNode;
    else{
        newNode->next=node->next;
        node->next=newNode;
    }
    return llist;
}
