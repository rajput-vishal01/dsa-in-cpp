#include <iostream> 
using namespace std; 

class Node{
  public:
  int data ;
  Node *ptr;

  // constructor 
  Node (int value){
    this->data = value;
    this->ptr = NULL;
  }
};

//returns head of new LL
Node* insertAtHead(int value, Node* &head, Node* &tail){
  //LL is empty, Head and Tail both are pointing to NULL
  //it means we are creating first node
  if(head == NULL && tail == NULL){
    //step 1:Create a New Node
    Node* newNode = new Node(value);
    //step 2: Head ko node pr lagao
    head = newNode;
    //step 3: tail ko newNode pe lagao
    tail = newNode;
  } else {
    //LL is not empty
    //insert at head
    //step1: create Node
    Node* newNode = new Node(value);
    //step2:Connect this new node to head
    newNode->ptr = head;
    //step 3: update head
    head = newNode;
  }
  return head;
}

Node* insertAtTail(int value, Node* &head, Node* &tail){
  //LL is empty 
  if(head == NULL && tail == NULL){
    //step 1:Create a New Node
    Node* newNode = new Node(value);
    //step 2: Head ko node pr lagao
    head = newNode;
    //step 3: tail ko newNode pe lagao
    tail = newNode;
  } else {
    //LL is not empty
    //insert at tail
    //step1: create Node
    Node* newNode = new Node(value);
    //step2:Connect this new node to tail
    tail->ptr = newNode;
    //step 3: update tail
    tail = newNode;
  }
  return head;
}

int getLenOfLL(Node* head){
  Node* temp = head;    
  int len = 0;
  while(temp != NULL){
    len++;
    temp = temp->ptr;
  }
  return len;
}

void printLinkedList(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout << temp->data << "->";
    temp = temp->ptr;
  }
  cout << "NULL" << endl;
}

//assume that position is valid
void insertAtPosition(int position, int value, Node* &head, Node* &tail){  
  if(position == 1){
    head = insertAtHead(value, head, tail);
  } else if(position == getLenOfLL(head) + 1){
    head = insertAtTail(value, head, tail);
  } else { 
    //insert in middle
    //step1: create Node
    Node* newNode = new Node(value);
    //step2:Connect this new node to tail
    Node* temp = head;
    for(int i = 1; i < position - 1; i++){
      temp = temp->ptr;
    }
    newNode->ptr = temp->ptr;
    temp->ptr = newNode;
  }
}

//search in LL
int findElem(int target, Node* head) {
  Node* temp = head;
  while(temp != NULL){
    if(temp->data == target){
      return true;
    }
    temp = temp->ptr;
  }
  return false;
}

void deleteNodefromLL(int position, Node* &head, Node* &tail){
  if(head == NULL && tail == NULL){
    cout << "Linked List is empty";
    return;
  }

  if(head == tail){
    Node* temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
  } else {
    //multiple nodes inside LL
    //2 cases
    //case 1: pos = 1
    if(position == 1){
      Node* temp = head;
      head = temp->ptr;
      temp->ptr = NULL;
      delete temp;
    } else {
      //case 2: any position except 1
      Node* prev = head;
      for(int i = 0; i < position - 2; i++){
        prev = prev->ptr;
      }
      Node* curr = prev->ptr;
      Node* forward = curr->ptr;
      prev->ptr = forward;
      if(forward == NULL){
        tail = prev;
      }
      curr->ptr = NULL;
      delete curr;
    }
  }
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;
 
  insertAtPosition(1, 10, head, tail);
  insertAtPosition(2, 20, head, tail);
  insertAtPosition(3, 30, head, tail);
  insertAtPosition(2, 100, head, tail);

  printLinkedList(head);

  // cout << findElem(100, head);

  deleteNodefromLL(3, head, tail);
  printLinkedList(head);
  
  return 0; 
}
