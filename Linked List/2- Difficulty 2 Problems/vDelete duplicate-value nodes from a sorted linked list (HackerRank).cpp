// Problem Link : https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

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


SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
  unordered_set<int> st;
  SinglyLinkedListNode* node=llist;
  int index=-1;
  while(node!=NULL){
    index++;
    if(st.find(node->data) != st.end()){
        deleteNode(llist,index);
        index--;
    }
    else st.insert(node->data);
    node=node->next;
  }
  return llist;
}
