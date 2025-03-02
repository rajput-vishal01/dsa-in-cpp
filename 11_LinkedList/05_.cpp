/*Find the middle node of LL

Approch 1: find length of LL(using length function) and then find middle element of LL by dividing length by 2 ----T.C = O(n) + O(n/2) ----> O(n)
Approch 2: using slow and fast pointer (tortoise and hare approch)  ----> T.C = O(n)

Leetcode Problem = 876

*/


// class Solution {
//   public:
//       ListNode* middleNode(ListNode* head) {
//           ListNode* fast = head;
//           ListNode* slow = head;
  
//           while(fast != NULL){
//               fast = fast->next;
//               if(fast != NULL ){
//                   slow=slow->next;
//                   fast  =fast->next;
//               }
  
//           }
//           return slow;
  
//       }
//   };
  