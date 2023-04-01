class LinkedList{
private:
  struct Node{
    int val=0;
    Node* nxt=NULL;
    Node(int _val) : val(_val){}
  };
  Node* head=NULL;
  Node* tail=NULL;

public:
  LinkedList(){
    head=tail=NULL;
  }

  void push_back(int val){
    Node* node=new Node(val);
    if(tail==NULL) head=tail=node;
    else{
      tail->nxt = node;
      tail=node;
    }
  }

  void pop_back(){
    if(tail==NULL) return;
    if(head==tail) head=tail=NULL;
    else{
      Node* node=head;
      while(node->nxt!=tail) node=node->nxt;
      node->nxt = NULL;
      tail=node;
    }
  }

  void push_front(int val){
    Node* node=new Node(val);
    if(tail==NULL) head=tail=node;
    else{
      node->nxt=head;
      head=node;
    }
  }

  void pop_front(){
    if(tail==NULL) return;
    if(head==tail) head=tail=NULL;
    else head=head->nxt;
  }
};
