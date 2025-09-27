//Add 1 to LinkedList:Gfg

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* &head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next =NULL;
        
        while(curr!=NULL){
           next=curr->next;
           curr->next=prev;
           
           prev=curr;
           curr=next;
        }
      
      return prev;
    
    }
    
    Node* addOne(Node* head) {
      //step 1: reverse a LL
      head=reverse(head);
      
      //step 2: add 1 :: carry ko hi one le lo 
      int carry = 1;
      
      Node* temp = head;
      while(temp!=NULL){

          int sum=carry+temp->data;
          
          //Node can only have single digit
          int digit = sum%10;
          carry=sum/10;
          
          temp->data=digit;
          
          if(carry!=0 && temp->next==NULL){
              Node* carryNode = new Node(carry);
              temp->next=carryNode;
              carry=0;
            }
          
          temp=temp->next;
      }
      
    
      //step 3: reverse again and return
      head=reverse(head);
      
      
      return head;
    }
};