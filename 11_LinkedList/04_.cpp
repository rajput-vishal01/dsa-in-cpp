/* Leetcode Problem  206*/
/* recursive approach
T.C=O(N)
S.C=O(N)
*/
// class Solution {

//   ListNode* reverse(ListNode* &prev,ListNode* &curr){
//    if(curr==NULL){
//        return prev;
//    }

//    ListNode* forward = curr->next;
//    curr->next=prev;

//    prev=curr;
//    curr=forward;

//    return reverse( prev,curr);

//   }



// public:
//    ListNode* reverseList(ListNode* head) {
       
//        ListNode* prev = NULL;
//        ListNode* curr = head;

//        ListNode* newHead = reverse(prev,curr);
//        return newHead;

//    }
// };



/*iterative approach
T.C = O(N)
S.C = O(1)

*/


// class Solution {


//   public:
//       ListNode* reverseList(ListNode* head) {
          
//           ListNode* prev = NULL;
//           ListNode* curr = head;
  
//           while(curr != NULL){
//               ListNode* forward = curr->next;
//               curr->next=prev;
  
//               prev=curr;
//               curr=forward;
//           } 
//           return prev;
  
//       }
//   };