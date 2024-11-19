// Problem Link : https://www.hackerrank.com/challenges/reverse-a-linked-list/problem

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
  SinglyLinkedListNode* node=llist;
  SinglyLinkedListNode* next=node->next;
  SinglyLinkedListNode* prev=NULL;
  while(true){
    node->next=prev;
    prev=node;
    node=next;
    if(node==NULL) break;
    next=node->next;
  }
  llist=prev;
  return llist;
}
