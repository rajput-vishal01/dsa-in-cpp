#include <iostream> 
using namespace std; 


class Node{
  public:
  int data ;
  Node *ptr;

  // constructor 
  Node (int value){
    this->data = value;
    this->ptr=NULL;
  }


};

//returns head of new LL
Node* insertAtHead(int value , Node* &head , Node* &tail){
  //LL is empty, Head and Tail both are pointing to NULL
  //it means we are creating first node
 if(head == NULL && tail == NULL){
  //step 1:Create a New Node
  Node* newNode = new Node(value);
  //step 2: Head ko node pr lagao
  head=newNode;
  //step 3: tail ko newNode pe lagao
  tail=newNode;
 }else{

  //LL is not empty
  //insert at head

  //step1: create Node
  Node* newNode = new Node(value);
  //step2:Connect this new node to head
  newNode->ptr=head;
  //step 3: update head
  head=newNode;
 }
 return head;

}

void printLinkedList(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp ->data <<"->";
    temp=temp->ptr;
  }
  cout<<"NULL"<<endl;
}


Node* insertAtTail(int value , Node* &head , Node* &tail){

  //LL is empty 
  if(head == NULL && tail == NULL){
    //step 1:Create a New Node
    Node* newNode = new Node(value);
    //step 2: Head ko node pr lagao
    head=newNode;
    //step 3: tail ko newNode pe lagao
    tail=newNode;
  }else{
    //LL is not empty
    //insert at tail
    //step1: create Node
    Node* newNode = new Node(value);
    //step2:Connect this new node to tail
    tail->ptr=newNode;
    //step 3: update tail
    tail=newNode;
  }

  return head;
};



int main() {

  //static memory allocation
  // Node n1;
  //dynamic memory allocation
  // Node *head = new Node(10); 

  Node* head = NULL;
  Node* tail = NULL;
//LL is empty
  insertAtHead(10,head,tail);
//10->Null
 head = insertAtHead(20,head,tail);
//20->10->Null
 head= insertAtHead(30,head,tail);
//30->20->10->Null
   
printLinkedList(head);


head = insertAtTail(40,head,tail);
head = insertAtTail(50,head,tail);
head = insertAtTail(60,head,tail);

printLinkedList(head);

  
    return 0; 
}
 