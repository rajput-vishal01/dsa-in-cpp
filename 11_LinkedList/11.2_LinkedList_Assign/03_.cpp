//HackerRank: print Kth node from the end

void fun(SinglyLinkedListNode* head, int &positionFromTail, int &ans){
    if(head==0) return ;
    fun(head->next ,positionFromTail,ans);
    //reached end
    if(positionFromTail==0){
        ans=head->data;
    }
    positionFromTail--;
    
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int ans=-1;
    fun(llist,positionFromTail,ans);
    return ans;

}