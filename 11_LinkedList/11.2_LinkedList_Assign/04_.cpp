//GFG : Intersection of Two Linked Lists
class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> map;
        Node* curr = head2;

        // hash data and occur. of l2 items
        while (curr) {
            map[curr->data]++;
            curr = curr->next;
        }

        Node* IL = NULL; // intersection LL
        Node* it = NULL; 
        curr = head1;

        while (curr) {
            if (map.find(curr->data) != map.end() && map[curr->data] > 0) {
                // node found append it
                if (!IL) {
                    // create head
                    IL = curr;
                    it = IL;
                } else {
                    it->next = curr;
                    it = it->next;
                }
                map[curr->data]--; // decrement occurrence
            }
            curr = curr->next;
        }

        if (it) it->next = NULL; // terminate intersection LL
        return IL;
    }
};