// GFG : Delete N nodes after M nodes of a linked list
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        if(!head || m == 0) return NULL;
        if(n == 0) return head;
        
        Node* current = head;
        
        // Keep the first m nodes
        for(int i = 0; i < m - 1 && current; i++) {
            current = current->next;
        }
        
        // If we don't have m nodes, return the original list
        if(!current) return head;
        
        // Now delete the next n nodes
        for(int i = 0; i < n && current->next; i++) {
            Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete nodeToDelete;
        }
        
        // Recursively process the rest of the list
        current->next = linkdelete(current->next, n, m);
        
        return head;
    }
};