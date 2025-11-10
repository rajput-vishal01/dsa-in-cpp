//gfg : union of two linked lists


class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        map<int,Node*>mp;
        Node* curr = head1;
        
        // Insert all elements from the first list
        while(curr){
            mp[curr->data]=curr;
            curr=curr->next;
        }
        
        // Insert all elements from the second list
        curr = head2;
        while(curr){
            mp[curr->data]=curr;
            curr=curr->next;
        }
        
        //create new LL using the map as map has unique and sorted elems
        Node* unionHead=NULL;
        curr=NULL;
        
        for(auto it=mp.begin(); it!=mp.end(); it++){
            Node* newNode = new Node(it->first);
            if(!unionHead){
                unionHead=newNode;
                curr=unionHead;
            }else{
                curr->next=newNode;
                curr=curr->next;
            }
        }
        curr->next=NULL;
        return unionHead;
    }
};