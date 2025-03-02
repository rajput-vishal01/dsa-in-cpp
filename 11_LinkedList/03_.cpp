#include <iostream> 
using namespace std; 

class Node{
  public:
  int data;
  Node* next;
  Node* prev;
  Node(int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
  }
};


Node* insertAtHead(Node* &head,Node* &tail,int data){
  if(head==NULL && tail==NULL){ 
    Node* newNode = new Node(data);
    head=newNode;
    tail=newNode;
}else{
  Node* newNode = new Node(data);
  newNode->next=head;
  head->prev=newNode;
  head=newNode;
}
return head;
}



void insertAtTail(Node* &head,Node* &tail,int data){
  if(head==NULL && tail==NULL){ 
    Node* newNode = new Node(data);
    head=newNode;
    tail=newNode;
}else{
  Node* newNode = new Node(data);
  tail->next=newNode; 
  newNode->prev=tail;
  tail=newNode;
}

}

int getLenOfLL(Node* &head){
  Node* temp=head;
  int len=0;
  while(temp!=NULL){
    len++;
    temp=temp->next;
  }
  return len;

}


void insertAtPosition(Node* &head,Node* &tail,int position,int data){
 
  if( position<0 && position>getLenOfLL(head)+1){
    cout<<"Invalid Position"<<endl;
    return;
  }

  if(position==1){
    insertAtHead(head,tail,data);
  }else if(position==getLenOfLL(head)+1){
    insertAtTail(head,tail,data);
  }else{
    Node* temp=head;
    for(int i=1;i<position-2;i++){
      temp=temp->next;
    }
    Node* newNode = new Node(data);
    Node* forward=temp->next; 
    newNode->prev=temp;
    newNode->next=forward;
    temp->next=newNode;
    forward->prev=newNode;
  }
}

bool searchElem(int target, Node* head, Node* tail) {
  
  Node* temp = head;
  while (temp != NULL) {
      if (temp->data == target) {
          return true;
      }
      temp = temp->next;
  }
  return false;
}




void deleteFromPosition(int position, Node* &head, Node* &tail) {
  int length = getLenOfLL(head);
  //LL is empty
  if(head == NULL && tail == NULL) {
    cout << "no nodes to delete" << endl;
    return;
  }
  else if(head == tail) {
    //single node to delete
    Node* temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
  }
  else if(position == 1) {
    //we want to delete head node
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
  }
  else if(length == position) {
    //we want to delete the tail node
    Node* temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
  }
  else {
    //we want to delete any other node than head and tail node
    Node* backward = head;
    for(int i=0; i<position-2; i++) {
      backward = backward -> next;
    }
    Node* curr = backward->next;
    Node* forward = curr->next;

    //pointers change
    backward->next = forward;
    forward->prev = backward;
    //curr ko isolate karna h 
    curr->prev = NULL;
    curr->next = NULL;
    //curr isolate ho chuka h 
    delete curr;

  }
}





void print(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

void printreverse(Node* tail){
  Node* temp=tail;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->prev;
  }
  cout<<"NULL"<<endl;
}


int main() {
   
  // Node* newNode = new Node(10);

  Node* head=NULL;
  Node* tail=NULL;
  insertAtHead(head,tail,10);
  insertAtHead(head,tail,20);
  insertAtHead(head,tail,30);
  print(head);
  // printreverse(tail);

  insertAtTail(head,tail,40);
  insertAtTail(head,tail,50);
  insertAtTail(head,tail,60);
  print(head);
  // printreverse(tail);


  insertAtPosition(head,tail,2,100);
  print(head);
  // printreverse(tail);

//  cout<< searchElem(40,head,tail);

 deleteFromPosition(4, head, tail);
 print(head);

  
    return 0; 
}
